/**
 * @file crud/interfaces.hpp
 * @author Perry Anderson (perry@exparx.com)
 * @brief crud/interfaces
 * @version 0.1
 * @date 2022-06-07
 *
 * @copyright (C) November 22, 2021 EXPARX INCORPORATED
 *
 */

#ifndef _EXTRAS_DBO_CRUD_INTERFACES_HPP
#define _EXTRAS_DBO_CRUD_INTERFACES_HPP

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
    namespace dbo {

        /**
         * @brief DatabaseParameters
         *
         */
        using CRUDUsername = std::string;
        using CRUDPassword = std::string;
        using CRUDServerURL = std::string;
        using CRUDRequest = std::string;
        using CRUDScript = std::string;
        using CRUDResponse = std::vector<std::string>;

        /**
         * @brief DatabaseInterface
         *
         */
        interface CRUDInterface
        {

            /**
             * @brief username()
             * @return username to a database
             */
            virtual const CRUDUsername& username() const pure;

            /**
             * @brief password()
             * @return password to a database
             */
            virtual const CRUDPassword& password() const pure;

            /**
             * @brief serverURL()
             * @return serverURL to a database
             */
            virtual const CRUDServerURL& serverURL() const pure;

            /**
             * @brief request()
             * @return execute an SQL request on the database
             */
            virtual CRUDResponse request(const CRUDRequest&) const pure;

            /**
             * @brief script()
             * @return execute an SQL script on the database
             */
            virtual CRUDResponse script(const CRUDScript&) const pure;

        };

        /**
         * @brief EndOfGameReachedException
         *
         */

        concrete class CRUDException
            extends extras::AbstractCustomException {
        public:
            CRUDException(
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

#endif // _EXTRAS_DBO_CRUD_INTERFACES_HPP
