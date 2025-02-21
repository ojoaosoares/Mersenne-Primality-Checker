#include "mersenne_numbers.hpp"

mpz_class n_mersenne_number(const long long& n) {

    return (2 << (n)) - 1;
}