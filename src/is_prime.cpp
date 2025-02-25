#include "is_prime.hpp"

bool is_prime(const unsigned long long &n) {
    
    if (!(n % 2) || n == 1) return false;

    long long start = 3;

    while (start * start < n)
    {
        if (!(n % start)) return false;

        start += 2;
    }
    
    return true;
}