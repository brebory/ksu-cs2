#ifndef BIGINT_H
#define BIGINT_H

#define POSITIVE true

namespace BigInt {

    // class BigInt implements an arbitrary-precision integer system.
    class BigInt {
        private:

            // class Numeral implements a linked list as BigInt's internal representation
            class Numeral {
                private:
                    Digit* _head;
                    int _length;

                public:

            };

            // class Digit defines nodes for Numeral's linked list
            class Digit {
                private:
                    int _digit;
                    Digit* _next;
                    Digit* _prev;

            };

            Numeral _numeral;
            bool _sign;

    };
}



#endif
