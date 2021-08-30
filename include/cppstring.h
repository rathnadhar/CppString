#pragma once

//MIT License

//Copyright (c) 2021 Rathnadhar K V

//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files (the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:

//The above copyright notice and this permission notice shall be included in all
//copies or substantial portions of the Software.

//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//SOFTWARE.

#include "cppstring_global.h"
#include <string>

namespace rathna
{
    class cppstring;
    using CPPSTRING_REF = cppstring& ;

    class CPPSTRING_EXPORT cppstring
    {
        private:
            std::string anvil;

        public:
            enum DESTINATION_STRING_MODIFICATION_TYPE
            {
                REPLACE,
                APPEND
            };

            /// Create a defult string object.
            /// Only Gurantee: cppstring length is zero.
            cppstring();

            /// Create a c'tor that is populated with chars (8bits), required number of times.
            /// The character in_character is copied in_count number of times.
            cppstring(const unsigned int in_count,
                      const char         in_char
                      );

            /// Set the string length to zero.
            void clear();

            /// First set all the character in the sting to 0x0
            /// and then set the size of the string to zero.
            /// This ensures that clear() does not leave arbitary code in the memory
            void wipe();

            /// Returns the number of characters in the string.
            /// size_t is unsigned integer type
            size_t length() const;

            /// Requests that the buffer capacity be reserved for planned change in size to a length
            /// of up to n characters.
            void reserve(size_t in_requeted_capacity = 0);

            /// Add string or char to the end of the string
            /// The stirng size is increased accordingly.
            CPPSTRING_REF append(const char in_char);

            /// Convert the string to uppper case
            void touppercase();

            /// Convert the string string to uppcase and return
            /// in the parameter.
            /// source string is unmodified.
            void touppercase(cppstring& out_upper_string,
                             rathna::cppstring::DESTINATION_STRING_MODIFICATION_TYPE in_modification_type_flag =
                                             rathna::cppstring::DESTINATION_STRING_MODIFICATION_TYPE::REPLACE
                             );

            /// Convert the string to uppper case
            CPPSTRING_REF tolowercase();

            /// Convert the string string to uppcase and return
            /// in the parameter.
            void tolowercase(cppstring& out_lower_string,
                             rathna::cppstring::DESTINATION_STRING_MODIFICATION_TYPE in_modification_type_flag =
                                             rathna::cppstring::DESTINATION_STRING_MODIFICATION_TYPE::REPLACE
                             );

            /// Declare the cppstring iterators
            typedef std::string::iterator       iterator;
            typedef std::string::const_iterator const_iterator;

            iterator begin();
            iterator end();
    };


}

//CPPSTRING.H
