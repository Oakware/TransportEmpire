// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include "Entity-odb.h"

#include <cassert>
#include <cstring>  // std::memcpy
#include <typeinfo>

#include <odb/polymorphic-map.hxx>

#include <odb/mssql/traits.hxx>
#include <odb/mssql/database.hxx>
#include <odb/mssql/transaction.hxx>
#include <odb/mssql/connection.hxx>
#include <odb/mssql/statement.hxx>
#include <odb/mssql/statement-cache.hxx>
#include <odb/mssql/polymorphic-object-statements.hxx>
#include <odb/mssql/container-statements.hxx>
#include <odb/mssql/exceptions.hxx>
#include <odb/mssql/polymorphic-object-result.hxx>

namespace odb
{
  // Entity
  //

  struct access::object_traits_impl< ::db::Entity, id_mssql >::extra_statement_cache_type
  {
    extra_statement_cache_type (
      mssql::connection&,
      image_type&,
      id_image_type&,
      mssql::binding&,
      mssql::binding&)
    {
    }
  };

  access::object_traits_impl< ::db::Entity, id_mssql >::id_type
  access::object_traits_impl< ::db::Entity, id_mssql >::
  id (const id_image_type& i)
  {
    mssql::database* db (0);
    ODB_POTENTIALLY_UNUSED (db);

    id_type id;
    {
      mssql::value_traits<
          unsigned int,
          mssql::id_int >::set_value (
        id,
        i.id_value,
        i.id_size_ind == SQL_NULL_DATA);
    }

    return id;
  }

  access::object_traits_impl< ::db::Entity, id_mssql >::id_type
  access::object_traits_impl< ::db::Entity, id_mssql >::
  id (const image_type& i)
  {
    mssql::database* db (0);
    ODB_POTENTIALLY_UNUSED (db);

    id_type id;
    {
      mssql::value_traits<
          unsigned int,
          mssql::id_int >::set_value (
        id,
        i.id_value,
        i.id_size_ind == SQL_NULL_DATA);
    }

    return id;
  }

  access::object_traits_impl< ::db::Entity, id_mssql >::version_type
  access::object_traits_impl< ::db::Entity, id_mssql >::
  version (const image_type& i)
  {
    version_type v;
    {
      mssql::value_traits<
          unsigned int,
          mssql::id_int >::set_value (
        v,
        i.version_value,
        i.version_size_ind == SQL_NULL_DATA);
    }

    return v;
  }

  access::object_traits_impl< ::db::Entity, id_mssql >::discriminator_type
  access::object_traits_impl< ::db::Entity, id_mssql >::
  discriminator (const image_type& i)
  {
    mssql::database* db (0);
    ODB_POTENTIALLY_UNUSED (db);

    discriminator_type d;
    {
      mssql::value_traits<
          ::std::string,
          mssql::id_string >::set_value (
        d,
        i.typeid_value,
        static_cast<std::size_t> (i.typeid_size_ind),
        i.typeid_size_ind == SQL_NULL_DATA);
    }

    return d;
  }

  void access::object_traits_impl< ::db::Entity, id_mssql >::
  bind (mssql::bind* b,
        image_type& i,
        mssql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mssql;

    std::size_t n (0);

    // id
    //
    if (sk != statement_insert && sk != statement_update)
    {
      b[n].type = mssql::bind::int_;
      b[n].buffer = &i.id_value;
      b[n].size_ind = &i.id_size_ind;
      n++;
    }

    // typeid_
    //
    if (sk != statement_update)
    {
      b[n].type = mssql::bind::string;
      b[n].buffer = &i.typeid_value;
      b[n].size_ind = &i.typeid_size_ind;
      b[n].capacity = static_cast<SQLLEN> (sizeof (i.typeid_value));
      n++;
    }

    // version
    //
    if (sk == statement_select)
    {
      b[n].type = mssql::bind::int_;
      b[n].buffer = &i.version_value;
      b[n].size_ind = &i.version_size_ind;
      n++;
    }
  }

  void access::object_traits_impl< ::db::Entity, id_mssql >::
  bind (mssql::bind* b, id_image_type& i, bool bv)
  {
    std::size_t n (0);
    b[n].type = mssql::bind::int_;
    b[n].buffer = &i.id_value;
    b[n].size_ind = &i.id_size_ind;
    if (bv)
    {
      n += 1;

      b[n].type = mssql::bind::int_;
      b[n].buffer = &i.version_value;
      b[n].size_ind = &i.version_size_ind;
    }
  }

  void access::object_traits_impl< ::db::Entity, id_mssql >::
  init (image_type& i,
        const object_type& o,
        mssql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mssql;

    if (i.change_callback_.callback != 0)
      (i.change_callback_.callback) (i.change_callback_.context);

    // typeid_
    //
    if (sk == statement_insert)
    {
      const info_type& di (map->find (typeid (o)));

      bool is_null (false);
      std::size_t size (0);
      mssql::value_traits<
          ::std::string,
          mssql::id_string >::set_image (
        i.typeid_value,
        sizeof (i.typeid_value) - 1,
        size,
        is_null,
        di.discriminator);
      i.typeid_size_ind =
        is_null ? SQL_NULL_DATA : static_cast<SQLLEN> (size);
    }
  }

  void access::object_traits_impl< ::db::Entity, id_mssql >::
  init (object_type& o,
        const image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // id
    //
    {
      unsigned int& v =
        o.id;

      mssql::value_traits<
          unsigned int,
          mssql::id_int >::set_value (
        v,
        i.id_value,
        i.id_size_ind == SQL_NULL_DATA);
    }

    // version
    //
    {
      unsigned int& v =
        o.version;

      mssql::value_traits<
          unsigned int,
          mssql::id_int >::set_value (
        v,
        i.version_value,
        i.version_size_ind == SQL_NULL_DATA);
    }
  }

  void access::object_traits_impl< ::db::Entity, id_mssql >::
  init (id_image_type& i, const id_type& id, const version_type* v)
  {
    {
      bool is_null (false);
      mssql::value_traits<
          unsigned int,
          mssql::id_int >::set_image (
        i.id_value, is_null, id);
      i.id_size_ind = is_null ? SQL_NULL_DATA : 0;
    }

    if (v != 0)
    {
      bool is_null (false);
      mssql::value_traits<
          unsigned int,
          mssql::id_int >::set_image (
        i.version_value, is_null, (*v));
      i.version_size_ind = is_null ? SQL_NULL_DATA : 0;
    }
  }

  access::object_traits_impl< ::db::Entity, id_mssql >::map_type*
  access::object_traits_impl< ::db::Entity, id_mssql >::map;

  const access::object_traits_impl< ::db::Entity, id_mssql >::info_type
  access::object_traits_impl< ::db::Entity, id_mssql >::info (
    typeid (::db::Entity),
    0,
    0,
    "db::Entity",
    &odb::create_impl< ::db::Entity >,
    &odb::dispatch_impl< ::db::Entity, id_mssql >,
    0);

  static const access::object_traits_impl< ::db::Entity, id_mssql >::entry_type
  polymorphic_entry_for_db_Entity;

  const char access::object_traits_impl< ::db::Entity, id_mssql >::persist_statement[] =
  "INSERT INTO [Entity] "
  "([typeid], "
  "[version]) "
  "OUTPUT INSERTED.[id] "
  "VALUES "
  "(?, 1)";

  const char access::object_traits_impl< ::db::Entity, id_mssql >::find_statement[] =
  "SELECT "
  "[Entity].[id], "
  "[Entity].[typeid], "
  "[Entity].[version] "
  "FROM [Entity] "
  "WHERE [Entity].[id]=?";

  const char access::object_traits_impl< ::db::Entity, id_mssql >::
  find_discriminator_statement[] =
  "SELECT "
  "[Entity].[typeid], "
  "[Entity].[version] "
  "FROM [Entity] "
  "WHERE [Entity].[id]=?";

  const char access::object_traits_impl< ::db::Entity, id_mssql >::update_statement[] =
  "UPDATE [Entity] "
  "SET "
  "[version]=[version]+1 "
  "WHERE [id]=? AND [version]=?";

  const char access::object_traits_impl< ::db::Entity, id_mssql >::erase_statement[] =
  "DELETE FROM [Entity] "
  "WHERE [id]=?";

  const char access::object_traits_impl< ::db::Entity, id_mssql >::optimistic_erase_statement[] =
  "DELETE FROM [Entity] "
  "WHERE [id]=? AND [version]=?";

  const char access::object_traits_impl< ::db::Entity, id_mssql >::query_statement[] =
  "SELECT "
  "[Entity].[id], "
  "[Entity].[typeid], "
  "[Entity].[version] "
  "FROM [Entity]";

  const char access::object_traits_impl< ::db::Entity, id_mssql >::erase_query_statement[] =
  "DELETE FROM [Entity]";

  const char access::object_traits_impl< ::db::Entity, id_mssql >::table_name[] =
  "[Entity]";

  void access::object_traits_impl< ::db::Entity, id_mssql >::
  persist (database& db, object_type& obj, bool top, bool dyn)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (top);

    using namespace mssql;

    if (dyn)
    {
      const std::type_info& t (typeid (obj));

      if (t != info.type)
      {
        const info_type& pi (root_traits::map->find (t));
        pi.dispatch (info_type::call_persist, db, &obj, 0);
        return;
      }
    }

    mssql::connection& conn (
      mssql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    if (top)
      callback (db,
                static_cast<const object_type&> (obj),
                callback_event::pre_persist);

    image_type& im (sts.image ());
    binding& imb (sts.insert_image_binding ());

    init (im, obj, statement_insert);

    if (im.version != sts.insert_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_insert);
      sts.insert_image_version (im.version);
      imb.version++;
    }

    {
      id_image_type& i (sts.id_image ());
      binding& b (sts.id_image_binding ());
      if (i.version != sts.id_image_version () || b.version == 0)
      {
        bind (b.bind, i);
        sts.id_image_version (i.version);
        b.version++;
        sts.optimistic_id_image_binding ().version++;
      }
    }

    insert_statement& st (sts.persist_statement ());
    if (!st.execute ())
      throw object_already_persistent ();

    obj.id = id (sts.id_image ());

    obj.version = 1;

    if (!top)
    {
      id_image_type& i (sts.id_image ());
      init (i, obj.id);

      binding& idb (sts.id_image_binding ());
      if (i.version != sts.id_image_version () || idb.version == 0)
      {
        bind (idb.bind, i);
        sts.id_image_version (i.version);
        idb.version++;
        sts.optimistic_id_image_binding ().version++;
      }
    }

    if (top)
      callback (db,
                static_cast<const object_type&> (obj),
                callback_event::post_persist);
  }

  void access::object_traits_impl< ::db::Entity, id_mssql >::
  update (database& db, const object_type& obj, bool top, bool dyn)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (top);

    using namespace mssql;
    using mssql::update_statement;

    if (dyn)
    {
      const std::type_info& t (typeid (obj));

      if (t != info.type)
      {
        const info_type& pi (root_traits::map->find (t));
        pi.dispatch (info_type::call_update, db, &obj, 0);
        return;
      }
    }

    if (top)
      callback (db, obj, callback_event::pre_update);

    mssql::transaction& tr (mssql::transaction::current ());
    mssql::connection& conn (tr.connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    const id_type& id (
      obj.id);
    const version_type& v (
      obj.version);
    id_image_type& idi (sts.id_image ());
    init (idi, id, &v);

    image_type& im (sts.image ());
    init (im, obj, statement_update);

    bool u (false);
    binding& imb (sts.update_image_binding ());
    if (im.version != sts.update_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_update);
      sts.update_image_version (im.version);
      imb.version++;
      u = true;
    }

    binding& idb (sts.id_image_binding ());
    if (idi.version != sts.update_id_image_version () ||
        idb.version == 0)
    {
      if (idi.version != sts.id_image_version () ||
          idb.version == 0)
      {
        bind (idb.bind, idi);
        sts.id_image_version (idi.version);
        idb.version++;
        sts.optimistic_id_image_binding ().version++;
      }

      sts.update_id_image_version (idi.version);

      if (!u)
        imb.version++;
    }

    update_statement& st (sts.update_statement ());
    if (st.execute () == 0)
      throw object_changed ();

    const_cast< object_type& > (obj).version++;

    if (top)
    {
      callback (db, obj, callback_event::post_update);
      pointer_cache_traits::update (db, obj);
    }
  }

  void access::object_traits_impl< ::db::Entity, id_mssql >::
  erase (database& db, const id_type& id, bool top, bool dyn)
  {
    using namespace mssql;

    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (top);

    mssql::connection& conn (
      mssql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    if (dyn)
    {
      discriminator_type d;
      root_traits::discriminator_ (sts.root_statements (), id, &d);

      if (d != info.discriminator)
      {
        const info_type& pi (root_traits::map->find (d));

        if (!pi.derived (info))
          throw object_not_persistent ();

        pi.dispatch (info_type::call_erase, db, 0, &id);
        return;
      }
    }

    if (top)
    {
      id_image_type& i (sts.id_image ());
      init (i, id);

      binding& idb (sts.id_image_binding ());
      if (i.version != sts.id_image_version () || idb.version == 0)
      {
        bind (idb.bind, i);
        sts.id_image_version (i.version);
        idb.version++;
        sts.optimistic_id_image_binding ().version++;
      }
    }

    if (sts.erase_statement ().execute () != 1)
      throw object_not_persistent ();

    if (top)
      pointer_cache_traits::erase (db, id);
  }

  void access::object_traits_impl< ::db::Entity, id_mssql >::
  erase (database& db, const object_type& obj, bool top, bool dyn)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (top);

    if (dyn)
    {
      const std::type_info& t (typeid (obj));

      if (t != info.type)
      {
        const info_type& pi (root_traits::map->find (t));
        pi.dispatch (info_type::call_erase, db, &obj, 0);
        return;
      }
    }

    using namespace mssql;

    mssql::connection& conn (
      mssql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    if (top)
      callback (db, obj, callback_event::pre_erase);

    const id_type& id  (
      obj.id);

    if (top)
    {
      const version_type& v (
        obj.version);
      id_image_type& i (sts.id_image ());
      init (i, id, &v);

      binding& idb (sts.id_image_binding ());
      if (i.version != sts.id_image_version () ||
          idb.version == 0)
      {
        bind (idb.bind, i);
        sts.id_image_version (i.version);
        idb.version++;
        sts.optimistic_id_image_binding ().version++;
      }
    }

    if (sts.optimistic_erase_statement ().execute () != 1)
      throw object_changed ();

    if (top)
    {
      pointer_cache_traits::erase (db, id);
      callback (db, obj, callback_event::post_erase);
    }
  }

  access::object_traits_impl< ::db::Entity, id_mssql >::pointer_type
  access::object_traits_impl< ::db::Entity, id_mssql >::
  find (database& db, const id_type& id)
  {
    using namespace mssql;

    {
      pointer_type p (pointer_cache_traits::find (db, id));

      if (!pointer_traits::null_ptr (p))
        return p;
    }

    mssql::connection& conn (
      mssql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);
    auto_result ar;
    root_traits::discriminator_type d;

    if (l.locked ())
    {
      if (!find_ (sts, &id))
        return pointer_type ();

      ar.set (sts.find_statement ());
      d = root_traits::discriminator (sts.image ());
    }
    else
      root_traits::discriminator_ (sts, id, &d);

    const info_type& pi (
      d == info.discriminator ? info : root_traits::map->find (d));

    pointer_type p (pi.create ());
    pointer_traits::guard pg (p);

    pointer_cache_traits::insert_guard ig (
      pointer_cache_traits::insert (db, id, p));

    object_type& obj (pointer_traits::get_ref (p));

    if (l.locked ())
    {
      select_statement& st (sts.find_statement ());
      ODB_POTENTIALLY_UNUSED (st);

      callback_event ce (callback_event::pre_load);
      pi.dispatch (info_type::call_callback, db, &obj, &ce);
      init (obj, sts.image (), &db);
      st.stream_result ();
      ar.free ();
      load_ (sts, obj, false);

      if (&pi != &info)
      {
        std::size_t d (depth);
        pi.dispatch (info_type::call_load, db, &obj, &d);
      }

      sts.load_delayed (0);
      l.unlock ();
      ce = callback_event::post_load;
      pi.dispatch (info_type::call_callback, db, &obj, &ce);
      pointer_cache_traits::load (ig.position ());
    }
    else
      sts.delay_load (id, obj, ig.position (), pi.delayed_loader);

    ig.release ();
    pg.release ();
    return p;
  }

  bool access::object_traits_impl< ::db::Entity, id_mssql >::
  find (database& db, const id_type& id, object_type& obj, bool dyn)
  {
    ODB_POTENTIALLY_UNUSED (dyn);

    using namespace mssql;

    if (dyn)
    {
      const std::type_info& t (typeid (obj));

      if (t != info.type)
      {
        const info_type& pi (root_traits::map->find (t));
        return pi.dispatch (info_type::call_find, db, &obj, &id);
      }
    }

    mssql::connection& conn (
      mssql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    auto_result ar (st);
    reference_cache_traits::position_type pos (
      reference_cache_traits::insert (db, id, obj));
    reference_cache_traits::insert_guard ig (pos);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    st.stream_result ();
    ar.free ();
    load_ (sts, obj, false);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    reference_cache_traits::load (pos);
    ig.release ();
    return true;
  }

  bool access::object_traits_impl< ::db::Entity, id_mssql >::
  reload (database& db, object_type& obj, bool dyn)
  {
    ODB_POTENTIALLY_UNUSED (dyn);

    using namespace mssql;

    if (dyn)
    {
      const std::type_info& t (typeid (obj));

      if (t != info.type)
      {
        const info_type& pi (root_traits::map->find (t));
        return pi.dispatch (info_type::call_reload, db, &obj, 0);
      }
    }

    mssql::connection& conn (
      mssql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    const id_type& id  (
      obj.id);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    auto_result ar (st);

    if (version (sts.image ()) == obj.version)
      return true;

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    st.stream_result ();
    ar.free ();
    load_ (sts, obj, true);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    return true;
  }

  bool access::object_traits_impl< ::db::Entity, id_mssql >::
  find_ (statements_type& sts,
         const id_type* id)
  {
    using namespace mssql;

    id_image_type& i (sts.id_image ());
    init (i, *id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
      sts.optimistic_id_image_binding ().version++;
    }

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    select_statement& st (sts.find_statement ());

    st.execute ();
    auto_result ar (st);
    select_statement::result r (st.fetch ());

    if (r != select_statement::no_data)
    {
      ar.release ();
      return true;
    }
    else
      return false;
  }

  void access::object_traits_impl< ::db::Entity, id_mssql >::
  discriminator_ (statements_type& sts,
                  const id_type& id,
                  discriminator_type* pd,
                  version_type* pv)
  {
    using namespace mssql;

    id_image_type& idi (sts.discriminator_id_image ());
    init (idi, id);

    binding& idb (sts.discriminator_id_image_binding ());
    if (idi.version != sts.discriminator_id_image_version () ||
        idb.version == 0)
    {
      bind (idb.bind, idi, false);
      sts.discriminator_id_image_version (idi.version);
      idb.version++;
    }

    discriminator_image_type& i (sts.discriminator_image ());
    binding& imb (sts.discriminator_image_binding ());

    if (i.version != sts.discriminator_image_version () ||
        imb.version == 0)
    {
      mssql::bind* b (imb.bind);
      std::size_t n (0);
      {
        b[n].type = mssql::bind::string;
        b[n].buffer = &i.discriminator_value;
        b[n].size_ind = &i.discriminator_size_ind;
        b[n].capacity = static_cast<SQLLEN> (sizeof (i.discriminator_value));
      }

      n++;
      {
        b[n].type = mssql::bind::int_;
        b[n].buffer = &i.version_value;
        b[n].size_ind = &i.version_size_ind;
      }

      sts.discriminator_image_version (i.version);
      imb.version++;
    }

    {
      select_statement& st (sts.find_discriminator_statement ());
      st.execute ();
      auto_result ar (st);
      select_statement::result r (st.fetch ());

      if (r == select_statement::no_data)
      {
        if (pv != 0)
          throw object_changed ();
        else
          throw object_not_persistent ();
      }
    }

    if (pd != 0)
    {
      discriminator_type& d (*pd);
      {
        mssql::value_traits<
            ::std::string,
            mssql::id_string >::set_value (
          d,
          i.discriminator_value,
          static_cast<std::size_t> (i.discriminator_size_ind),
          i.discriminator_size_ind == SQL_NULL_DATA);
      }
    }

    if (pv != 0)
    {
      version_type& v (*pv);
      {
        mssql::value_traits<
            unsigned int,
            mssql::id_int >::set_value (
          v,
          i.version_value,
          i.version_size_ind == SQL_NULL_DATA);
      }
    }
  }

  result< access::object_traits_impl< ::db::Entity, id_mssql >::object_type >
  access::object_traits_impl< ::db::Entity, id_mssql >::
  query (database&, const query_base_type& q)
  {
    using namespace mssql;
    using odb::details::shared;
    using odb::details::shared_ptr;

    mssql::connection& conn (
      mssql::transaction::current ().connection ());

    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    std::string text (query_statement);
    if (!q.empty ())
    {
      text += " ";
      text += q.clause ();
    }

    q.init_parameters ();
    shared_ptr<select_statement> st (
      new (shared) select_statement (
        conn,
        text,
        false,
        true,
        q.parameters_binding (),
        imb));

    st->execute ();

    shared_ptr< odb::polymorphic_object_result_impl<object_type> > r (
      new (shared) mssql::polymorphic_object_result_impl<object_type> (
        q, st, sts, 0));

    return result<object_type> (r);
  }

  unsigned long long access::object_traits_impl< ::db::Entity, id_mssql >::
  erase_query (database&, const query_base_type& q)
  {
    using namespace mssql;

    mssql::connection& conn (
      mssql::transaction::current ().connection ());

    std::string text (erase_query_statement);
    if (!q.empty ())
    {
      text += ' ';
      text += q.clause ();
    }

    q.init_parameters ();
    delete_statement st (
      conn,
      text,
      q.parameters_binding ());

    return st.execute ();
  }
}

#include <odb/post.hxx>
