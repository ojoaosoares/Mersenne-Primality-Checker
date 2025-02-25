#include "fermat_method.hpp"
#include <cmath>

mpz_class fermat_method(const mpz_class &M, const unsigned long long& p) 
{   
    mpz_class twop = 2;
    mpz_mul_ui(twop.get_mpz_t(), twop.get_mpz_t(), p);

    mpz_class q = 1 + twop;

    mpz_class r = 1;

    mpz_class N = ((mpz_class(1) << (std::ceil(p / 2.0))) - 1) / twop;

    while (r < N)
    {
        if ((M % q) == 0)
            return q;

        q += twop;
        r++;
    }
    
    return M;
}