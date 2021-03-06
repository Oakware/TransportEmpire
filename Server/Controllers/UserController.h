#pragma once

#include "Server/Controller.h"

namespace srv {

class db::IDatabase;
class db::EntityManager;
class UserController : public IController
{
public:
    UserController(db::IDatabase* database);

private:
    static Response login(const Request& request, db::EntityManager* manager);

protected:
    RequestHandler requestHandler(Request::Type requestType) override;
};

} // srv namespace
