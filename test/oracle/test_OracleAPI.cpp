// /**
//  * @brief the "MIT/X Consortium License", (adapted for EXPARX.COM)
//  *
//  * Copyright (C) November 22, 2021 EXPARX INCORPORATED
//  *
//  * Permission is hereby  granted,  free of charge,  to  any  person
//  * obtaining a copy of this software and  associated  documentation
//  * files   (the  "Software"),  to deal  in   the  Software  without
//  * restriction, including  without  limitation the rights  to  use,
//  * copy,  modify, merge,  publish,  distribute,  sublicense, and/or
//  * sell copies of the  Software, and to permit persons  to whom the
//  * Software  is  furnished to  do  so,  subject  to  the  following
//  * conditions:
//  *
//  * (See LICENSE.md for complete details)
//  *
//  */

// #include <iostream>
// #include <occi.h>
// #include <bits/c++config.h>
// #include <pthread.h>

// #include "../vendor/catch.hpp"

// using namespace oracle::occi;
// using namespace std;


// SCENARIO("Verify Oracle Instant Client example", "[OracleSDK]")
// {
//     const string userName = "HR";
//     const string password = "password";
//     const string connectString = "";

//     try {
//         Environment* env = Environment::createEnvironment();
//         {
//             Connection* conn = env->createConnection(
//                 userName, password, connectString);
//             Statement* stmt = conn->createStatement(
//                 "SELECT blobcol FROM mytable");
//             ResultSet* rs = stmt->executeQuery();
//             rs->next();
//             Blob b = rs->getBlob(1);
//             cout << "Length of BLOB : " << b.length();
//             stmt->closeResultSet(rs);
//             conn->terminateStatement(stmt);
//             env->terminateConnection(conn);
//         }
//         Environment::terminateEnvironment(env);
//     }
//     catch (SQLException& ex) {
//         cout << ex.getMessage() << endl;
//     }
// }

