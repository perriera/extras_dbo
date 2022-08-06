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

// #include <cppconn/driver.h>
// #include <cppconn/exception.h>
// #include <cppconn/resultset.h>
// #include <cppconn/statement.h>
// #include <cppconn/prepared_statement.h>


// #include "../vendor/catch.hpp"

// using namespace std;


// SCENARIO("Verify MySQL", "[OracleSDK]")
// {
//     cout << endl;
//     cout << "Running 'SELECT 'Hello World!' AS _message'..." << endl;

//     try {
//         sql::Driver* driver;
//         sql::Connection* con;
//         sql::Statement* stmt;
//         sql::ResultSet* res;

//         /* Create a connection */
//         driver = get_driver_instance();
//         con = driver->connect("tcp://127.0.0.1:3306", "sammy", "password");
//         /* Connect to the MySQL test database */
//         con->setSchema("test");

//         stmt = con->createStatement();
//         res = stmt->executeQuery("SELECT 'Hello World!' AS _message");
//         while (res->next()) {
//             cout << "\t... MySQL replies: ";
//             /* Access column data by alias or column name */
//             cout << res->getString("_message") << endl;
//             cout << "\t... MySQL says it again: ";
//             /* Access column data by numeric offset, 1 is the first column */
//             cout << res->getString(1) << endl;
//         }
//         delete res;
//         delete stmt;
//         delete con;

//     }
//     catch (sql::SQLException& e) {
//         cout << "# ERR: SQLException in " << __FILE__;
//         cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
//         cout << "# ERR: " << e.what();
//         cout << " (MySQL error code: " << e.getErrorCode();
//         cout << ", SQLState: " << e.getSQLState() << " )" << endl;
//     }

// }
