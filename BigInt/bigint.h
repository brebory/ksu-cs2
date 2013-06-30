#include <vector>
#include <sstream>
#include <string>

class BigInt {
    friend std::ostream& operator<<(std::ostream&, const BigInt&);
    friend BigInt operator+(const BigInt&, const BigInt&);
    friend BigInt operator*(const BigInt&, const BigInt&);
    friend std::istream& operator>>(std::istream&, BigInt&);
    public:
        BigInt();
        BigInt(int, int radix = 10);
        BigInt(const std::string&, int radix = 10);
        BigInt(const BigInt&);
        std::string to_string() const;
        BigInt& operator+=(const BigInt&);
        BigInt& operator++();
        BigInt operator++(int);
        BigInt& operator*=(const BigInt&);
        int operator[](int) const;
        int& operator[](int);
        bool is_zero() const;
        void times_10(int);
        void times_single_digit(int);
        int size() const;
    private:
        std::vector<int> _digits; 
        int _radix;
};
