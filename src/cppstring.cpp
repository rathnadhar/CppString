// Class cppstring::Ultimate C++ String library. -*- C++ -*-

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

#include "../include/cppstring.h"

namespace rathna
{
    cppstring::cppstring()
        :anvil()
    {

    }

    cppstring::iterator cppstring::begin()
    {
        return anvil.begin();
    }

    cppstring::iterator cppstring::end()
    {
        return anvil.end();
    }

    /// Set the string length to zero.
    void cppstring::clear()
    {
        this->anvil.clear();
    }

    /// First set all the character in the sting to 0x0
    /// and then set the size of the string to zero.
    /// This ensures that clear() does not leave arbitary code in the memory
    void cppstring::wipe()
    {
        auto index = this->anvil.begin();
        auto end = this->anvil.end();

        // Convert to upper: clear the '32' bit, 0x20 in hex. And with the
        // inverted bit string (~).
        while(index != end)
        {
            *index = 0x0;
            ++index;
        }
    }

    /// Returns the number of characters in the string.
    size_t cppstring::length() const
    {
       return (this->anvil.length());
    }

    /// Add string or char to the end of the string
    /// The stirng size is increased accordingly.
    void cppstring::append(const char in_char)
    {
        this->anvil.append(&in_char);
    }

    /// Requests that the buffer capacity be reserved for planned change in size to a length
    /// of up to n characters.
    void cppstring::reserve(size_t in_requeted_capacity)
    {
        this->anvil.reserve(in_requeted_capacity);
    }

    ///Convert the string to uppper case
    void cppstring::touppercase()
    {
        auto index = this->anvil.begin();
        auto end = this->anvil.end();

        // Convert to upper: clear the '32' bit, 0x20 in hex. And with the
        // inverted bit string (~).
        while(index != end)
        {
            if( *index >= (static_cast<unsigned char>('a'))
                &&
                *index <= (static_cast<unsigned char>('z'))
              )
            {
                *index &= ~0x20;
            }

            ++index;
        }
    }

    ///Convert the string string to upper case and return
    ///in the parameter.
    void cppstring::touppercase(cppstring& out_upper_string,
                                rathna::cppstring::DESTINATION_STRING_MODIFICATION_TYPE in_modification_type_flag
                                )
    {
        auto index = this->anvil.begin();
        auto end = this->anvil.end();

        if(in_modification_type_flag == rathna::cppstring::DESTINATION_STRING_MODIFICATION_TYPE::REPLACE)
        {
            // first clear out the out string
            out_upper_string.clear();
        }

        //upfront reserve the space so as to reduce the memory allocation bottleneck
        out_upper_string.reserve(this->length());

        // Convert to upper: clear the '32' bit, 0x20 in hex. And with the
        // inverted bit string (~).
        while(index != end)
        {
            if( *index >= (static_cast<unsigned char>('a'))
                    &&
                    *index <= (static_cast<unsigned char>('z'))
                    )
            {
                out_upper_string.append(static_cast<unsigned char>((*index) & (~0x20)));
            }

            ++index;
        }
    }

    ///Convert the string to lower case
    void cppstring::tolowercase()
    {
        auto index = this->anvil.begin();
        auto end = this->anvil.end();

        // Convert to upper: clear the '32' bit, 0x20 in hex. And with the
        // inverted bit string (~).
        while(index != end)
        {
            if( *index >= (static_cast<unsigned char>('a'))
                &&
                *index <= (static_cast<unsigned char>('z'))
              )
            {
                *index |= 0x20;
            }

            ++index;
        }
    }

    ///Convert the string string to lower case and return
    ///in the parameter.
    void cppstring::tolowercase(cppstring& out_lower_string,
                                rathna::cppstring::DESTINATION_STRING_MODIFICATION_TYPE in_modification_type_flag
                                )
    {
        auto index = this->anvil.begin();
        auto end = this->anvil.end();

        if(in_modification_type_flag == rathna::cppstring::DESTINATION_STRING_MODIFICATION_TYPE::REPLACE)
        {
            // first clear out the out string
            out_lower_string.clear();
        }

        //upfront reserve the space so as to reduce the memory allocation bottleneck
        out_lower_string.reserve(this->length());

        // Convert to upper: clear the '32' bit, 0x20 in hex. And with the
        // inverted bit string (~).
        while(index != end)
        {
            if( *index >= (static_cast<unsigned char>('a'))
                    &&
                    *index <= (static_cast<unsigned char>('z'))
                    )
            {
                out_lower_string.append(static_cast<unsigned char>((*index) | (0x20)));
            }

            ++index;
        }
    }
}
