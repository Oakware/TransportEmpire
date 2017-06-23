// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include "City-odb.h"

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
  // City
  //

  struct access::object_traits_impl< ::City, id_mssql >::extra_statement_cache_type
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

  void access::object_traits_impl< ::City, id_mssql >::
  bind (mssql::bind* b,
        const mssql::bind* id,
        std::size_t id_size,
        image_type& i,
        mssql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mssql;

    std::size_t n (0);

    // id
    //
    if (sk == statement_insert)
    {
      if (id != 0)
        std::memcpy (&b[n], id, id_size * sizeof (id[0]));
      n += id_size;
    }

    // placeID
    //
    b[n].type = mssql::bind::string;
    b[n].buffer = &i.placeID_value;
    b[n].size_ind = &i.placeID_size_ind;
    b[n].capacity = static_cast<SQLLEN> (sizeof (i.placeID_value));
    n++;

    // formatedAddress
    //
    b[n].type = mssql::bind::string;
    b[n].buffer = &i.formatedAddress_value;
    b[n].size_ind = &i.formatedAddress_size_ind;
    b[n].capacity = static_cast<SQLLEN> (sizeof (i.formatedAddress_value));
    n++;

    // location
    //
    composite_value_traits< ::Location, id_mssql >::bind (
      b + n, i.location_value, sk);
    n += 2UL;

    // id
    //
    if (sk == statement_update)
    {
      if (id != 0)
        std::memcpy (&b[n], id, id_size * sizeof (id[0]));
      n += id_size;
    }

    // Entity base
    //
    if (sk == statement_select)
      base_traits::bind (b + n, *i.base, sk);
  }

  void access::object_traits_impl< ::City, id_mssql >::
  init (image_type& i,
        const object_type& o,
        mssql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mssql;

    {
      root_traits::image_type& ri (root_image (i));

      if (ri.change_callback_.callback != 0)
        (ri.change_callback_.callback) (ri.change_callback_.context);
    }

    // placeID
    //
    {
      ::QString const& v =
        o.placeID;

      bool is_null (true);
      std::size_t size (0);
      mssql::value_traits<
          ::QString,
          mssql::id_string >::set_image (
        i.placeID_value,
        sizeof (i.placeID_value) - 1,
        size,
        is_null,
        v);
      i.placeID_size_ind =
        is_null ? SQL_NULL_DATA : static_cast<SQLLEN> (size);
    }

    // formatedAddress
    //
    {
      ::QString const& v =
        o.formatedAddress;

      bool is_null (true);
      std::size_t size (0);
      mssql::value_traits<
          ::QString,
          mssql::id_string >::set_image (
        i.formatedAddress_value,
        sizeof (i.formatedAddress_value) - 1,
        size,
        is_null,
        v);
      i.formatedAddress_size_ind =
        is_null ? SQL_NULL_DATA : static_cast<SQLLEN> (size);
    }

    // location
    //
    {
      ::Location const& v =
        o.location;

      composite_value_traits< ::Location, id_mssql >::init (
        i.location_value,
        v,
        sk);
    }
  }

  void access::object_traits_impl< ::City, id_mssql >::
  init (object_type& o,
        const image_type& i,
        database* db,
        std::size_t d)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // Entity base
    //
    if (--d != 0)
      base_traits::init (o, *i.base, db);

    // placeID
    //
    {
      ::QString& v =
        o.placeID;

      mssql::value_traits<
          ::QString,
          mssql::id_string >::set_value (
        v,
        i.placeID_value,
        static_cast<std::size_t> (i.placeID_size_ind),
        i.placeID_size_ind == SQL_NULL_DATA);
    }

    // formatedAddress
    //
    {
      ::QString& v =
        o.formatedAddress;

      mssql::value_traits<
          ::QString,
          mssql::id_string >::set_value (
        v,
        i.formatedAddress_value,
        static_cast<std::size_t> (i.formatedAddress_size_ind),
        i.formatedAddress_size_ind == SQL_NULL_DATA);
    }

    // location
    //
    {
      ::Location& v =
        o.location;

      composite_value_traits< ::Location, id_mssql >::init (
        v,
        i.location_value,
        db);
    }
  }

  const access::object_traits_impl< ::City, id_mssql >::info_type
  access::object_traits_impl< ::City, id_mssql >::info (
    typeid (::City),
    &object_traits_impl< ::db::Entity, id_mssql >::info,
    0,
    "City",
    &odb::create_impl< ::City >,
    &odb::dispatch_impl< ::City, id_mssql >,
    &statements_type::delayed_loader);

  static const access::object_traits_impl< ::City, id_mssql >::entry_type
  polymorphic_entry_for_City;

  const char access::object_traits_impl< ::City, id_mssql >::persist_statement[] =
  "INSERT INTO [City] "
  "([id], "
  "[placeID], "
  "[formatedAddress], "
  "[location_lat], "
  "[location_lng]) "
  "VALUES "
  "(?, ?, ?, ?, ?)";

  const char* const access::object_traits_impl< ::City, id_mssql >::find_statements[] =
  {
    "SELECT "
    "[City].[placeID], "
    "[City].[formatedAddress], "
    "[City].[location_lat], "
    "[City].[location_lng], "
    "[Entity].[id], "
    "[Entity].[typeid], "
    "[Entity].[version] "
    "FROM [City] "
    "LEFT JOIN [Entity] ON [Entity].[id]=[City].[id] "
    "WHERE [City].[id]=?",

    "SELECT "
    "[City].[placeID], "
    "[City].[formatedAddress], "
    "[City].[location_lat], "
    "[City].[location_lng] "
    "FROM [City] "
    "WHERE [City].[id]=?"
  };

  const std::size_t access::object_traits_impl< ::City, id_mssql >::find_column_counts[] =
  {
    7UL,
    4UL
  };

  const char access::object_traits_impl< ::City, id_mssql >::update_statement[] =
  "UPDATE [City] "
  "SET "
  "[placeID]=?, "
  "[formatedAddress]=?, "
  "[location_lat]=?, "
  "[location_lng]=? "
  "WHERE [id]=?";

  const char access::object_traits_impl< ::City, id_mssql >::erase_statement[] =
  "DELETE FROM [City] "
  "WHERE [id]=?";

  const char access::object_traits_impl< ::City, id_mssql >::query_statement[] =
  "SELECT\n"
  "[City].[placeID],\n"
  "[City].[formatedAddress],\n"
  "[City].[location_lat],\n"
  "[City].[location_lng],\n"
  "[Entity].[id],\n"
  "[Entity].[typeid],\n"
  "[Entity].[version]\n"
  "FROM [City]\n"
  "LEFT JOIN [Entity] ON [Entity].[id]=[City].[id]";

  const char access::object_traits_impl< ::City, id_mssql >::erase_query_statement[] =
  "DELETE FROM [City]";

  const char access::object_traits_impl< ::City, id_mssql >::table_name[] =
  "[City]";

  void access::object_traits_impl< ::City, id_mssql >::
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

    base_traits::persist (db, obj, false, false);

    image_type& im (sts.image ());
    binding& imb (sts.insert_image_binding ());
    const binding& idb (sts.id_image_binding ());

    init (im, obj, statement_insert);

    if (idb.version != sts.insert_id_binding_version () ||
        im.version != sts.insert_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, idb.bind, idb.count, im, statement_insert);
      sts.insert_id_binding_version (idb.version);
      sts.insert_image_version (im.version);
      imb.version++;
    }

    insert_statement& st (sts.persist_statement ());
    if (!st.execute ())
      throw object_already_persistent ();

    if (top)
      callback (db,
                static_cast<const object_type&> (obj),
                callback_event::post_persist);
  }

  void access::object_traits_impl< ::City, id_mssql >::
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

    base_traits::update (db, obj, false, false);

    image_type& im (sts.image ());
    init (im, obj, statement_update);

    const binding& idb (sts.id_image_binding ());
    binding& imb (sts.update_image_binding ());
    if (idb.version != sts.update_id_binding_version () ||
        im.version != sts.update_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, idb.bind, idb.count, im, statement_update);
      sts.update_id_binding_version (idb.version);
      sts.update_image_version (im.version);
      imb.version++;
    }

    update_statement& st (sts.update_statement ());
    if (st.execute () == 0)
      throw object_not_persistent ();

    if (top)
    {
      callback (db, obj, callback_event::post_update);
      pointer_cache_traits::update (db, obj);
    }
  }

  void access::object_traits_impl< ::City, id_mssql >::
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

    base_traits::erase (db, id, false, false);

    if (top)
      pointer_cache_traits::erase (db, id);
  }

  void access::object_traits_impl< ::City, id_mssql >::
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

    root_statements_type& rsts (sts.root_statements ());
    ODB_POTENTIALLY_UNUSED (rsts);

    if (top)
      callback (db, obj, callback_event::pre_erase);

    const id_type& id  (
      obj.id);

    if (top)
    {
      const version_type& v (
        obj.version);
      id_image_type& i (rsts.id_image ());
      init (i, id, &v);

      binding& idb (rsts.id_image_binding ());
      if (i.version != rsts.id_image_version () ||
          idb.version == 0)
      {
        bind (idb.bind, i);
        rsts.id_image_version (i.version);
        idb.version++;
        rsts.optimistic_id_image_binding ().version++;
      }
    }

    if (top)
    {
      version_type v;
      root_traits::discriminator_ (rsts, id, 0, &v);

      if (v != obj.version)
        throw object_changed ();
    }

    if (sts.erase_statement ().execute () != 1)
      throw object_changed ();

    base_traits::erase (db, obj, false, false);

    if (top)
    {
      pointer_cache_traits::erase (db, id);
      callback (db, obj, callback_event::post_erase);
    }
  }

  access::object_traits_impl< ::City, id_mssql >::pointer_type
  access::object_traits_impl< ::City, id_mssql >::
  find (database& db, const id_type& id)
  {
    using namespace mssql;

    {
      root_traits::pointer_type rp (pointer_cache_traits::find (db, id));

      if (!root_traits::pointer_traits::null_ptr (rp))
        return
          root_traits::pointer_traits::dynamic_pointer_cast<object_type> (rp);
    }

    mssql::connection& conn (
      mssql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());
    root_statements_type& rsts (sts.root_statements ());

    statements_type::auto_lock l (rsts);
    auto_result ar;
    root_traits::discriminator_type d;

    if (l.locked ())
    {
      if (!find_ (sts, &id))
        return pointer_type ();

      ar.set (sts.find_statement (depth));
      d = root_traits::discriminator (rsts.image ());
    }
    else
      root_traits::discriminator_ (rsts, id, &d);

    const info_type& pi (
      d == info.discriminator ? info : root_traits::map->find (d));

    root_traits::pointer_type rp (pi.create ());
    pointer_type p (
      root_traits::pointer_traits::static_pointer_cast<object_type> (rp));
    pointer_traits::guard pg (p);

    pointer_cache_traits::insert_guard ig (
      pointer_cache_traits::insert (db, id, rp));

    object_type& obj (pointer_traits::get_ref (p));

    if (l.locked ())
    {
      select_statement& st (sts.find_statement (depth));
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

      rsts.load_delayed (0);
      l.unlock ();
      ce = callback_event::post_load;
      pi.dispatch (info_type::call_callback, db, &obj, &ce);
      pointer_cache_traits::load (ig.position ());
    }
    else
      rsts.delay_load (id, obj, ig.position (), pi.delayed_loader);

    ig.release ();
    pg.release ();
    return p;
  }

  bool access::object_traits_impl< ::City, id_mssql >::
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
    root_statements_type& rsts (sts.root_statements ());

    statements_type::auto_lock l (rsts);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement (depth));
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
    rsts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    reference_cache_traits::load (pos);
    ig.release ();
    return true;
  }

  bool access::object_traits_impl< ::City, id_mssql >::
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
    root_statements_type& rsts (sts.root_statements ());

    statements_type::auto_lock l (rsts);

    const id_type& id  (
      obj.id);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement (depth));
    ODB_POTENTIALLY_UNUSED (st);

    auto_result ar (st);

    if (root_traits::version (rsts.image ()) == obj.version)
      return true;

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    st.stream_result ();
    ar.free ();
    load_ (sts, obj, true);
    rsts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    return true;
  }

  bool access::object_traits_impl< ::City, id_mssql >::
  find_ (statements_type& sts,
         const id_type* id,
         std::size_t d)
  {
    using namespace mssql;

    if (d == depth)
    {
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
    }

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding (d));

    if (imb.version == 0 ||
        check_version (sts.select_image_versions (), im))
    {
      bind (imb.bind, 0, 0, im, statement_select);
      update_version (sts.select_image_versions (),
                      im,
                      sts.select_image_bindings ());
    }

    select_statement& st (sts.find_statement (d));

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

  void access::object_traits_impl< ::City, id_mssql >::
  load_ (statements_type& sts,
         object_type& obj,
         bool reload,
         std::size_t d)
  {
    ODB_POTENTIALLY_UNUSED (reload);

    if (--d != 0)
      base_traits::load_ (sts.base_statements (), obj, reload);
  }

  void access::object_traits_impl< ::City, id_mssql >::
  load_ (database& db, root_type& r, std::size_t d)
  {
    using namespace mssql;

    object_type& obj (static_cast<object_type&> (r));
    mssql::connection& conn (
      mssql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    d = depth - d;

    if (!find_ (sts, 0, d))
      throw object_not_persistent ();

    select_statement& st (sts.find_statement (d));
    ODB_POTENTIALLY_UNUSED (st);

    auto_result ar (st);
    init (obj, sts.image (), &db, d);
    st.stream_result ();
    ar.free ();
    load_ (sts, obj, false, d);
  }

  result< access::object_traits_impl< ::City, id_mssql >::object_type >
  access::object_traits_impl< ::City, id_mssql >::
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
    binding& imb (sts.select_image_binding (depth));

    if (imb.version == 0 ||
        check_version (sts.select_image_versions (), im))
    {
      bind (imb.bind, 0, 0, im, statement_select);
      update_version (sts.select_image_versions (),
                      im,
                      sts.select_image_bindings ());
    }

    std::string text (query_statement);
    if (!q.empty ())
    {
      text += "\n";
      text += q.clause ();
    }

    q.init_parameters ();
    shared_ptr<select_statement> st (
      new (shared) select_statement (
        conn,
        text,
        true,
        true,
        q.parameters_binding (),
        imb));

    st->execute ();

    shared_ptr< odb::polymorphic_object_result_impl<object_type> > r (
      new (shared) mssql::polymorphic_object_result_impl<object_type> (
        q, st, sts, 0));

    return result<object_type> (r);
  }

  unsigned long long access::object_traits_impl< ::City, id_mssql >::
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