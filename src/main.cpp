#include <iostream>
#include "lucas_lehmer_test.hpp"
#include "mersenne_numbers.hpp"
#include "is_prime.hpp"

using namespace std;

void usage() {
    std::cout << "Usage: ./mersenne_primality_test [N] [-n]\n"
              << "  [N]   - Index of the Mersenne number to be tested (e.g., 5 for M_5 = 2^5 - 1)\n"
              << "  -n    - Prints the corresponding Mersenne number\n";
}


int main(int argc, char const *argv[])
{
    if (argc < 2 || argc > 3)
    {
        usage();
        return 1;
    }

    bool show = false;

    if (argc == 3)
    {
        if (argv[2] != "-n")
        {
            usage();
            return 1;
        }
        
        show = true;
    }        

    long long n = atoll(argv[1]);

    if (!is_prime(n))
    {
        cerr << n << " is not a odd prime number\n";
        usage();
        return 1;
    }

    mpz_class M = n_mersenne_number(n);

    cout << "The "<< n << "º Mersenne number (2^"  << n << " - 1) ";

    if (lucas_lehmer_test(M, n))
        cout << "is a prime number\n";

    else
        cout << "is not a prime number\n";

    if (show)
        cout << M << '\n';
    
    return 0;
}
