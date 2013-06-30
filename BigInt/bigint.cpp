#include "bigint.h"
#include <iostream>

BigInt::BigInt()
    : _digits(1), _radix(10) {
        // Default ctor
}

BigInt::BigInt(int num, int radix)
    : _radix(radix) {
    // int ctor

    // Special case for when num == 0
    if (num == 0) {
        _digits.push_back(num);
        return;
    }

    // Get each digit of num and add it to _digits
    for( ; num > 0; num /= radix) {
        _digits.push_back(num % radix);
    }
}

BigInt::BigInt(const std::string& source, int radix) 
    : _radix(radix) {
    // std::string ctor
    
    int digit;
    std::stringstream ss;

    // Convert each char in the string to an int and store in _digits.
    for(std::string::const_reverse_iterator i = source.rbegin(); i != source.rend(); ++i) {
        ss << *i;
        ss >> digit;
        
        if(ss) {
            _digits.push_back(digit);
        }
        
        ss.str(std::string());
        ss.clear();
    }
}

BigInt::BigInt(const BigInt& source)
    : _digits(source._digits), _radix(source._radix) { }

std::string BigInt::to_string() const {
    std::string result;
    std::stringstream ss;
    std::string digit_string;

    for(std::vector<int>::const_reverse_iterator i = _digits.rbegin(); i != _digits.rend(); ++i) {
        // Convert value at *i from int to std::string using std::stringstream
        ss << *i;
        ss >> digit_string;

        // Append converted string to result
        result += digit_string;

        // Reset std::stringstream
        ss.str(std::string());
        ss.clear();
    }
    return result;
}

std::ostream& operator<<(std::ostream& out, const BigInt& ref) {
    out << ref.to_string(); 
    return out;
}

BigInt::BigInt& BigInt::operator+=(const BigInt& rhs) {
    int carry = 0, temp = 0;
    std::vector<int>::size_type li, ri, ll, rl;

    // If lhs BigInt is smaller than rhs BigInt, resize lhs.
    if(_digits.size() < rhs._digits.size()) {
        _digits.resize(rhs._digits.size(), 0);
    }

    // Long addition with carries.
    for(li = 0, ri = 0, ll = _digits.size(), rl = rhs._digits.size(); (li < ll) && (ri < rl); ++li, ++ri) {
        // Need to store results in a temp variable to make all calculations atomic.
        temp = (_digits.at(li) + rhs._digits.at(ri) + carry) % _radix;
        carry = (_digits.at(li) + rhs._digits.at(ri) + carry) / _radix;
        _digits.at(li) = temp;
    }
    for( ; (li < ll) && carry; ++li) {
        // Again, temp variable for atomic calculations
        temp = (_digits.at(li) + carry) % _radix;
        carry = (_digits.at(li) + carry) / _radix;
        _digits.at(li) = temp;
    }
    while(carry) {
        _digits.push_back(carry % _radix);
        carry = carry / _radix;
    }
    
    return *this;
}

BigInt::BigInt operator+(const BigInt& lhs, const BigInt& rhs) {
    BigInt::BigInt result(lhs);
    result += rhs;
    return result;
}

BigInt::BigInt& BigInt::operator++() {
    return *this += 1;
}

BigInt::BigInt BigInt::operator++(int x) {
    BigInt::BigInt result(*this);
    *this += 1;
    return result;
}

BigInt::BigInt& BigInt::operator*=(const BigInt& rhs) {
    BigInt::BigInt original(*this);
    std::vector<int>::size_type i, l;

    *this = BigInt(0);

    if(rhs.is_zero()) {
        return *this;
    }

    for(i = 0, l = rhs._digits.size(); i < l; ++i) {
        BigInt::BigInt intermediate(original);
        intermediate.times_single_digit(rhs._digits.at(i));
        intermediate.times_10((int)i);
        *this += intermediate;
    }

    return *this; 
}

int BigInt::operator[](int index) const {
    return _digits.at(index);
}
int& BigInt::operator[](int index) {
    return _digits.at(index);
}

BigInt::BigInt operator*(const BigInt& lhs, const BigInt& rhs) {
    BigInt::BigInt result(lhs);
    result *= rhs;
    return result;
}

std::istream& operator>>(std::istream& in, BigInt::BigInt& container) {
    std::string line;
    std::getline(in, line);
    if(in) {
        BigInt::BigInt result(line);
        container = result;
    }
    return in;
}

bool BigInt::is_zero() const {
    return (_digits.size() == 1) && (_digits.at(0) == 0);
}

void BigInt::times_10(int exponent) {
    if(is_zero()) {
        return;
    }
    
    // Insert zeros at the front of _digits
    for(int i = 0; i < exponent; ++i) {
        _digits.insert(_digits.begin(), 0);
    }
}

void BigInt::times_single_digit(int n) {
    int carry = 0, temp = 0;
    std::vector<int>::size_type i, l;
    if(is_zero()) {
        return;
    }
    if(n == 0) {
        _digits.clear();
        _digits.push_back(0);
        return;
    }
    for(i = 0, l = _digits.size(); i < l; ++i) {
        temp = (_digits.at(i) * n + carry) % _radix;
        carry = (_digits.at(i) * n + carry) / _radix;
        _digits.at(i) = temp;
    }
    while(carry) {
        _digits.push_back(carry % _radix);
        carry = carry / _radix;
    }
}

int BigInt::size() const {
    return _digits.size();
}
