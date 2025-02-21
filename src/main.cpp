#include <iostream>
#include "mersenne_numbers.hpp"
#include "lucas_lehmer_test.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    if (argc != 2)
        return 1;

    cout <<  lucas_lehmer_test(atoll(argv[1])) << '\n';
    
    return 0;
}
