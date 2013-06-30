#include <iostream>
#include "bigint.h"

BigInt::BigInt factorial(const int&);
int count_zeroes(const BigInt::BigInt&);

int main(int argc, char **argv) {
    if(argc != 2) {
        std::cerr << "\tWrong number of arguments.\n\tUsage: " << argv[0] << " <number>" << std::endl;
        return 1;
    }

    int fact;
    std::stringstream ss;
    BigInt::BigInt result;
    ss << std::string(argv[1]);
    ss >> fact;
    std::cout << "The factorial of:\n\t" << fact << std::endl;
    std::cout << "is:\n\t" << (result = factorial(fact)) << std::endl;
    std::cout << "The number of 10 factors is: " << count_zeroes(result) << std::endl;

    return 0;
}

BigInt::BigInt factorial(const int& base) {
    if(base <= 0) {
        return 1;
    }
    return BigInt(base) * factorial(base - 1);
}

int count_zeroes(const BigInt::BigInt& n) {
    int result = 0, counter = 0;
    while(counter < n.size()) {
        if(n[counter] == 0) {
            result++;
        } else {
            break;
        }
        counter++;
    }
    return result;
}

