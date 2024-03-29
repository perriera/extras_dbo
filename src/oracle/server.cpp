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

// #include <extras_dbo/oracle/server.hpp>
// #include <iostream>

// using namespace std;
// using namespace extras;
// using namespace oracle::occi;

// void dbo::OracleServer::connect(const ServerParameters& params) {
//     _env = Environment::createEnvironment(Environment::DEFAULT);
//     _conn = _env->createConnection(params[1], params[2], params[0]);
// }

// void dbo::OracleServer::disconnect() {
//     _env->terminateConnection(_conn);
//     Environment::terminateEnvironment(_env);
//     _conn = nullptr;
//     _env = nullptr;
// }
