#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
    friend std::ostream& operator<<(std::ostream&, const Rational&);

    private:
        // Private members
        int  _numerator;
        int  _denominator;

        // Private member functions
        int  gcd(int lg, int sm);
        void reduce();

    public:
        Rational::Rational(int num = 0, int denom = 1)
            :_numerator(num), _denominator(denom)
        {}
};
#endif
