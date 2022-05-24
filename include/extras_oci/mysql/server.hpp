/**
 * @file Server.hpp
 * @author Perry Anderson (perry@exparx.com)
 * @brief Sample Server
 * @version 0.1
 * @date 2021-11-30
 *
 * @copyright (C) November 22, 2021 EXPARX INCORPORATED
 *
 */

#ifndef _MYSQLSERVER_HPP
#define _MYSQLSERVER_HPP

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
#include <extras_oci/server.hpp>

namespace extras {
    namespace oci {

        /**
         * @brief ChessGame
         *
         */
        concrete class MySQLServer implements ServerInterface
        {
        public:

            /**
             * @brief ServerInterface
             */
            virtual void connect(const ServerParameters&) const override;
            virtual void disconnect() const override;

        };


    } // end namespace 
}

#endif // _MYSQLSERVER_HPP
