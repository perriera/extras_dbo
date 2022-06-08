/**
 * @brief the "MIT/X Consortium License", (adapted for EXPARX.COM)
 *
 * Copyright (C) November 22, 2021 EXPARX INCORPORATED
 *
 * Permission is hereby  granted,  free of charge,  to  any  person
 * obtaining a copy of this software and  associated  documentation
 * files   (the  "Software"),  to deal  in   the  Software  without
 * restriction, including  without  limitation the rights  to  use,
 * copy,  modify, merge,  publish,  distribute,  sublicense, and/or
 * sell copies of the  Software, and to permit persons  to whom the
 * Software  is  furnished to  do  so,  subject  to  the  following
 * conditions:
 *
 * (See LICENSE.md for complete details)
 *
 */

#include <iostream>
#include <extras_dbo/crud/interfaces.hpp>
#include <extras/docking/DockIt.hpp>

#include "../vendor/catch.hpp"
#include "../vendor/fakeit.hpp"

using namespace extras;
using namespace fakeit;

SCENARIO("Dock CRUDInterface: request", "[DBO-4]") {

    Dock<dbo::CRUDInterface> dock;
    When(Method(dock, username)).Return("username");
    When(Method(dock, password)).Return("password");
    When(Method(dock, request)).AlwaysDo([](const dbo::CRUDRequest&) {
        return dbo::CRUDResponse();
        });

    dbo::CRUDInterface& i = dock.get();
    dbo::CRUDScript request("SELECT USERNAME FROM ALL_USERS ORDER BY USERNAME;");
    dbo::CRUDResponse response = i.request(request);

    REQUIRE(i.username() == "username");
    REQUIRE(i.password() == "password");
    REQUIRE(response == dbo::CRUDResponse());

    Verify(Method(dock, username));
    Verify(Method(dock, password));
    Verify(Method(dock, request));
}

SCENARIO("Dock CRUDInterface: script", "[DBO-4]") {

    Dock<dbo::CRUDInterface> dock;
    When(Method(dock, username)).Return("username");
    When(Method(dock, password)).Return("password");
    When(Method(dock, script)).AlwaysDo([](const dbo::CRUDScript&) {
        return dbo::CRUDResponse();
        });

    dbo::CRUDInterface& i = dock.get();
    dbo::CRUDScript script("etc/test.sql");
    dbo::CRUDResponse response = i.script(script);

    REQUIRE(i.username() == "username");
    REQUIRE(i.password() == "password");
    REQUIRE(response == dbo::CRUDResponse());

    Verify(Method(dock, username));
    Verify(Method(dock, password));
    Verify(Method(dock, script));
}
