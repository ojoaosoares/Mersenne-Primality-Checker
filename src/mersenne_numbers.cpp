#include "mersenne_numbers.hpp"

mpz_class n_mersenne_number(const mpz_class& mk, const long long &k, const long long& n) {

    mpz_class two_power_n = (mk + 1) << (n - k);

    return two_power_n - 1;
}