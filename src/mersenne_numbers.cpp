#include "mersenne_numbers.hpp"

mpz_class n_mersenne_number(const unsigned long long& n) {
    
    return (mpz_class(1) << n) - 1;
}
