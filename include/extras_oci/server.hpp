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

#ifndef _SERVER_HPP
#define _SERVER_HPP

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
#include <extras/interfaces.hpp>

namespace extras {
    namespace oci {

        /**
         * @brief ServerParameters
         *
         */
        using ServerParameters = std::vector<std::string>;

        /**
         * @brief ServerInterface
         *
         */
        interface ServerInterface
        {

            /**
             * @brief connect()
             * @return connect to a database
             */
            virtual void connect(const ServerParameters&) const pure;

            /**
             * @brief disconnect()
             * @return disconnect from a database
             */
            virtual void disconnect() const pure;

        };

        /**
         * @brief EndOfGameReachedException
         *
         */

        concrete class ServerException
            extends extras::AbstractCustomException {
        public:
            ServerException(
                const std::string& msg,
                const extras::WhereAmI& whereAmI)
                : AbstractCustomException(msg.c_str(),
                    whereAmI._file.c_str(),
                    whereAmI._func.c_str(), whereAmI._line) {}
            static void assertion(
                int sizePGN, int sizeFEN,
                const std::string& msg,
                const extras::WhereAmI& ref);
        };

    } // end namespace 
}

#endif // _SERVER_HPP
