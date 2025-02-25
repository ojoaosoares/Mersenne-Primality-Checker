#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "lucas_lehmer_test.hpp"
#include "mersenne_numbers.hpp"
#include "is_prime.hpp"
#include "fermat_method.hpp"

using namespace std;

void usage() {
    std::cout << "Usage: ./mersenne_primality_test -i [N] [-m METHOD] [-n]\n"
              << "  -i index   - Index of the Mersenne number to be tested (e.g., 5 for M_5 = 2^5 - 1)\n"
              << "  -m METHOD  - Method LL for Lucas Lehmer method or F for Fermat method (LL method is default)\n"
              << "  -n         - Prints the corresponding Mersenne number\n";
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        usage();
        return 1;
    }

    unsigned long long n = 0; // Inicializa o índice
    bool show = false;
    std::string method = "LL"; // Método padrão

    int opt;
    while ((opt = getopt(argc, argv, "i:m:n")) != -1) {
        switch (opt) {
            case 'i':
                n = std::atoll(optarg); // Armazena o índice do número de Mersenne
                break;
            case 'm':
                method = optarg;
                break;
            case 'n':
                show = true;
                break;
            default:
                usage();
                return 1;
        }
    }

    if (n == 0) {
        usage();
        return 1;
    }

    if (!is_prime(n))
    {
        cerr << n << " is not a odd prime number\n";
        usage();
        return 1;
    }

    mpz_class M = n_mersenne_number(n);

    cout << "The "<< n << "º Mersenne number (2^"  << n << " - 1) ";

    if (method == "LL")
    {
        if (lucas_lehmer_test(M, n))
            cout << "is a prime number\n";

        else
            cout << "is not a prime number\n";
    }

    else if (method == "F")
    {
        mpz_class factor = fermat_method(M, n);

        if (factor == M)
            cout << "is a prime number\n";

        else
            cout << "is not a prime number\nThe smallest factor is " << factor << '\n';
    }

    

    if (show)
        cout << M << '\n';
    
    return 0;
}
