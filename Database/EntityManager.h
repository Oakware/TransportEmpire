#pragma once

#include <odb/database.hxx>
#include <odb/mssql/database.hxx>
#include <odb/query.hxx>
#include <odb/core.hxx>
#include <odb/session.hxx>

#include <QObject>
#include <QVector>

#include <type_traits>

#include "Database/Pointer.h"
#include "Database/Entity.h"

namespace db
{

template<typename T>
using Query = odb::query<T>;

class EntityManager : public QObject
{
    Q_OBJECT
    friend class Transaction;
private:
    odb::database* db = nullptr;
    odb::session session;

public:
    EntityManager(odb::database* _db);
    virtual ~EntityManager() = default;

public:
    void startSession();

    void persist(Entity& entity);
    void persist(Pointer<Entity> entity);

private:
    void track(Entity* entity);

private slots:
    void onUpdateRequested();
    void onReloadRequested();
    void onEraseRequested();

signals:
    void entityUpdated(Entity* entity);

public:
    template<class T>
    Pointer<T> load(unsigned int id);

    template<class T>
    void reload(Pointer<T> entity);

    template<class T>
    Pointer<T> queryOne(const Query<T>& _query);

    template<class T>
    QVector<Pointer<T>> query();

    template<class T>
    QVector<Pointer<T>> query(const Query<T>& _query);

    template<class T>
    LazyPointer<T> loadLater(unsigned int id);

    template<class T>
    LazyPointer<T> queryOneLater(const Query<T>& _query);

    template<class T>
    QVector<LazyPointer<T>> queryLater();

    template<class T>
    QVector<LazyPointer<T>> queryLater(const Query<T>& _query);

    template<class T>
    void erase();

    template<class T>
    void erase(const Query<T>& _query);

    template<class T>
    QVector<unsigned int> queryIds(const Query<T>* _query = nullptr);

    template<class Action>
    auto transactive(Action action);

private:
    template<class Action>
    void _transactive(Action action, std::true_type);
    template<class Action>
    auto _transactive(Action action, std::false_type);
};

}   // namespace db

#include "EntityManager-inl.h"


