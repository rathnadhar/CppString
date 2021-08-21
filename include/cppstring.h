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
    class CPPSTRING_EXPORT cppstring
    {
        private:
            std::string anvil;

        public:
            cppstring();

            /// Convert the string to uppper case
            void touppercase();

            /// Convert the string string to uppcase and return
            /// in the parameter.
            /// source string is unmodified.
            void touppercase(cppstring& out_upper_string);

            /// Convert the string to uppper case
            void tolowercase();

            /// Convert the string string to uppcase and return
            /// in the parameter.
            void tolowercase(cppstring& out_lower_string);

            /// Declare the cppstring iterators
            typedef std::string::iterator       iterator;
            typedef std::string::const_iterator const_iterator;

            iterator begin();
            iterator end();
    };


}

//CPPSTRING.H
