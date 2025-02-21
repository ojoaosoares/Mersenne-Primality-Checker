#include "mersenne_numbers.hpp"

mpz_class n_mersenne_number(const long long& n) {
    
    return (mpz_class(1) << n) - 1;
}
