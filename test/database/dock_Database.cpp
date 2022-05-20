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
#include <extras_oci/database.hpp>

#include "../vendor/catch.hpp"
#include "../vendor/fakeit.hpp"

using namespace extras;
using namespace fakeit;

SCENARIO("Dock Database: connect/disconnect", "[CHES-9]") {

    Dock<oci::DatabaseInterface> mock;
    When(Method(mock, connect)).Return();
    When(Method(mock, disconnect)).Return();

    oci::DatabaseInterface& i = mock.get();
    i.connect();
    i.disconnect();
    Verify(Method(mock, connect));
    Verify(Method(mock, disconnect));
}