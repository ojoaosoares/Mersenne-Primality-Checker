#include <iostream>
#include "lucas_lehmer_test.hpp"
#include "mersenne_numbers.hpp"
#include "is_prime.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    if (argc != 2)
        return 1;

    long long n = atoll(argv[1]);

    if (!is_prime(n))
    {
        cerr << n << " is not a odd prime number\n";
        return 1;
    }

    mpz_class M = n_mersenne_number(n);

    cout << M << '\n';

    cout << "The "<< n << "º Mersenne number (2^"  << n << " - 1) ";

    if (lucas_lehmer_test(M, n))
        cout << "is a prime number\n";

    else
        cout << "is not a prime number\n";
    
    return 0;
}
