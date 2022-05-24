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
#include <extras/docking/DockIt.hpp>
#include <extras_oci/server.hpp>

#include "../vendor/catch.hpp"
#include "../vendor/fakeit.hpp"

using namespace extras;
using namespace fakeit;

SCENARIO("Dock ServerInterface: connect/disconnect", "[SISPJCLA22-26]") {

    Dock<oci::ServerInterface> dock;
    When(Method(dock, connect)).AlwaysDo([](const oci::ServerParameters&) {
        return;
        });
    When(Method(dock, disconnect)).Return();

    oci::ServerInterface& i = dock.get();
    oci::ServerParameters params;
    i.connect(params);
    i.disconnect();
    Verify(Method(dock, connect));
    Verify(Method(dock, disconnect));
}

// https://exerror.com/failed-error-set-password-has-no-significance-for-user-rootlocalhost-as-the-authentication-method-used-doesnt-store-authentication-data-in-the-mysql-server/
// https://exerror.com/failed-error-set-password-has-no-significance-for-user-rootlocalhost-as-the-authentication-method-used-doesnt-store-authentication-data-in-the-mysql-server/
// https://www.digitalocean.com/community/tutorials/how-to-install-mysql-on-ubuntu-20-04


SCENARIO("Dock ServerInterface: parameters", "[SISPJCLA22-26]") {
    /**
     * @brief Simulate a class and class members here
     *
     * An octal number has a range of 0 to 7, (which is
     * ideal for chess positions for either row or col).
     *
     * In this case we will setup two char values to hold
     * the octal values for a chess piecee, row & col.
     */
    Dock<oci::ServerInterface> dock;
    When(Method(dock, connect)).AlwaysDo([](const oci::ServerParameters& params) {
        for (auto param : params)
            std::cout << param << std::endl;
        return;
        });
    When(Method(dock, disconnect)).Return();
    oci::ServerInterface& i = dock.get();

    /**
     * @brief Test a value of a1 in octal
     *
     */
    oci::ServerParameters params = { "tcp://127.0.0.1:3306", "sammy", "password" };
    i.connect(params);
    i.disconnect();

    Verify(Method(dock, connect));
    Verify(Method(dock, disconnect));
}