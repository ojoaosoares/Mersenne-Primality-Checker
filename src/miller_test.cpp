#include "miller_test.hpp"
#include "ak_mod_n.hpp"

bool miller_test(const mpz_class& a, const mpz_class& n, const mpz_class& first_power, const mpz_class& times)
{
    // Description : verifies if fermat theorm is satisfied
    // Input : a, n, first_power, times
    // Output : true/false
    // Complexity : O(log (n - 1))

    mpz_class a_powered_first_power;

    a_powered_first_power = ak_mod_n(a, first_power, n);

    if (a_powered_first_power == 1)
        return true;
    // If a_powered_first_power mod n is equal to 1, (a_powered_first_power)^2^q mode n will be equal 1
    
    for (mpz_class i = 0; i < times; i++)
    {

        if ((a_powered_first_power - n) == -1) // If (a_powered_first_power mod n)^2^i mode n is equal to -1, (a_powered_first_power)^2^q mode n will be equal 1
            return true;
        
        a_powered_first_power = (a_powered_first_power*a_powered_first_power) % n;
    }

    // Else, the number doens't fullfill Fermat theorem, not a prime
    return false;
}