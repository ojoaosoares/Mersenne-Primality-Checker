#include "miller_rabin.hpp"
#include "miller_test.hpp"
#include <time.h>

#define TEST_GOES_WRONG 0.25
#define EPSILON 1e-300 // Arround de 500 interactions

double miller_rabin(const mpz_class& n)
{
    // Description : verifies in a probabilisty way if n is prime
    // Input : n
    // Output : double
    // Complexity : O(k* log (n - 1))

    if (n > 3)
    {
        mpz_class count, first_odd_power;
        
        first_odd_power = n - 1;

        while ((first_odd_power & 1) == 0)
        {
            first_odd_power >>= 1;
            count++;
        }
        mpz_class test;

        double goes_wrong = 1;

        gmp_randclass rand_gen(gmp_randinit_default);
        rand_gen.seed(time(nullptr));

        while (goes_wrong > EPSILON)   
        {           
            test = rand_gen.get_z_range(n - 3) + 2;
            
            if(!miller_test(test, n, first_odd_power, count))
                return 0;    

            goes_wrong *= TEST_GOES_WRONG;
        }

        return 1 - goes_wrong;
    }

    else if (n >= 2)
        return 1;

    else
        return 0;
    
}