/*
 * Brendon Roberto
 * CS23001 SUMMER 2013
 *
 * Project: String
 * string.cpp - string library implementation
 *
 */

#include <cstring>
#include <iostream>
#include "string.h"

namespace cs23001 {

    string::string():_cap(0), _len(0), _str(new char[0]) {}

    string::string(const char *source)
        : _cap(strlen(source)), _len(_cap), _str(new char[_cap]) {
        for(size_type idx = 0; source[idx] != '\0'; ++idx) {
            _str[idx] = source[idx];
        }
    }

    string::string(const string& source)
        :_cap(source._cap), _len(source._len), _str(new char[_cap]) {
        for(size_type idx = 0; idx < _len; ++idx) {
            _str[idx] = source._str[idx];
        }
    }

    string::string(int n, char c)
        :_cap(n), _len(n), _str(new char[_cap]) {
       for(size_type idx = 0; idx < n; ++idx) {
            _str[idx] = c;
       }
    }

    string::~string() {
        delete[] _str;
    }

    void string::_increase_capacity(size_type amount) {
        if(amount == 0) {
            if(_cap == 0) {
                ++_cap;
            }
           amount = _cap * 2; 
        }
        char *temp = new char[amount];
        for(size_type idx = 0; idx < _len; ++idx) {
            temp[idx] = _str[idx];
        }
        delete[] _str;
        _str = temp;
        _cap = amount;
    }

    bool string::operator==(const string& rhs) const {
        if(_len != rhs._len) {
            return false;
        } else {
            for(size_type idx = 0; idx < _len; ++idx) {
                if(_str[idx] != rhs._str[idx]) {
                    return false;
                }
            }
        }
        return true;
    }

    char& string::operator[](size_type idx) {
        return _str[idx];
    }
    char string::operator[](size_type idx) const {
        return _str[idx];
    }

    string& string::operator=(const string& rhs) {
        delete[] _str;
        _cap = rhs._cap;
        _len = rhs._len;
        _str = new char[_cap];
        for(char *lit = _str, *rit = rhs._str,  *end = _str + _cap;
                  lit != end; 
                  *lit++ = *rit++);

        return *this;
    }

    string& string::operator+=(const char rhs) {
        if(_len < _cap) {
            _str[_len] = rhs;
        } else {
           _increase_capacity();
           _str[_len] = rhs;
        }
        ++_len;
        return *this;
    }

    string& string::operator+=(const string& rhs) {
        if((_len + rhs._len) < _cap) {
            for(size_type idx = 0; idx < rhs._len; ++idx) {
                _str[_len + idx] = rhs._str[idx];
            }
        } else {
            _increase_capacity(_len + rhs._len);
            for(size_type idx = 0; idx < rhs._len; ++idx) {
                _str[_len + idx] = rhs._str[idx];
            }
        }
        _len += rhs._len;
        return *this;
    }

    string operator+(const string& lhs, char rhs) {
        string result(lhs);
        result += rhs;
        return result;
    }

    string operator+(const string& lhs, const string& rhs) {
        string result(lhs);
        result += rhs;
        return result;
    }

    bool operator<(const string& lhs, const string& rhs) {
        bool result = lhs._len < rhs._len;
        for(string::size_type idx = 0; (idx < lhs._len) && (idx < rhs._len); ++idx) {
            if(lhs[idx] > rhs[idx]) {
                result = false;
                break;
            } else if(lhs[idx] < rhs[idx]) {
                result = true;
                break;
            }
        }
        return result;
    }

    bool operator<=(const string& lhs, const string& rhs) {
        return (lhs == rhs) || (lhs < rhs);
    }

    bool operator>(const string& lhs, const string& rhs) {
        return !(lhs <= rhs);
    }
    
    bool operator>=(const string& lhs, const string& rhs) {
        return !(lhs < rhs);
    }

    bool operator!=(const string& lhs, const string& rhs) {
        return !(lhs == rhs);
    }

    std::ostream& operator<<(std::ostream& out, const string& ref) {
        out << ref._str;
        return out;
    }

    std::istream& operator>>(std::istream& in, string& ref) {
        std::istream::sentry sentry(in); 
        const int BUFF_SIZE = 256;
        char buff[BUFF_SIZE];
        ref.resize(0);

        if(sentry) while(in.good()) {
            in.get(buff, BUFF_SIZE, ' '); 
            in.ignore(' ');
            ref += string(buff);
        }
        return in;
    }

    std::istream& getline(std::istream& in, string& ref) {
        std::istream::sentry sentry(in);
        const int BUFF_SIZE = 256;
        char buff[BUFF_SIZE];
        ref.resize(0);

        if(sentry) while(in.good()) {
            in.get(buff, BUFF_SIZE);
            ref += string(buff);
        }
        in.ignore('\n');
        return in;
    }

    string::size_type string::size() const {
        return _len;
    }

    string::size_type string::capacity() const {
        return _cap;
    }

    const char* string::c_str() {
        if(_len < _cap) {
            _str[_len + 1] = '\0';
            return _str;
        } else {
            _increase_capacity();
            _str[_len + 1] = '\0';
            return _str;
        }
    }

    void string::swap(string& other) {
        char *temp_str = _str;
        size_type temp_cap = _cap;
        size_type temp_len = _len;
        _str = other._str;
        _cap = other._cap;
        _len = other._len;
        other._str = temp_str;
        other._cap = temp_cap;
        other._len = temp_len;
    }

    void string::resize(size_type new_size) {
        if(new_size < _cap) {
            _len = new_size;
        } else {
            if(new_size > _cap) {
                _increase_capacity(new_size);
            }
            _len = new_size;
        }
    }

    void string::clear() {
        _len = 0;
    }

    string string::substr(size_type start, size_type length) {
        string result("");
        for(size_type idx = start; (idx < _len) && (idx < start + length); ++idx) {
            result += _str[idx];
        }
        return result;
    }

    string::size_type string::find(string& target, size_type start_index) {
        size_type result = -1;
        for(size_type this_idx = start_index, target_idx = 0; (this_idx < _len) && (target_idx < target._len); ++this_idx) {

            // Corner case for when the end of this string matches part of target.
            if((this_idx + 1 == _len) && (target_idx + 1 != target._len)) {
                result = -1;
            }

            if(_str[this_idx] == target[target_idx]) {
                // If we aren't already matching a substring, record the current index in result
                if(target_idx == 0) {
                    result = this_idx;
                }
                // Advance lookahead to next character in substring
                ++target_idx;
            } else {
                // There was no match this iteration
                if(target_idx != 0) {
                    // If we were matching a substring, match this index against the beginning of the stubstring on the next iteration
                    --this_idx;
                }
                target_idx = 0;
                result = -1;
            }
        }
        return result;
    }
}
