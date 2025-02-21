#include <iostream>
#include "mersenne_numbers.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    if (argc != 2)
        return 1;

    cout << n_mersenne_number(0, 0, atoll(argv[1])) << '\n';
    
    return 0;
}
