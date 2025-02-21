#include "lucas_lehmer_test.hpp"
#include "mersenne_numbers.hpp"

bool lucas_lehmer_test(const mpz_class &M, const long long& n) {

    mpz_class last_sequence_number = 4;

    for (size_t i = 0; i < n - 2; i++)
        last_sequence_number = (last_sequence_number * last_sequence_number - 2) % M;
    
    return (last_sequence_number % M) == 0;
}