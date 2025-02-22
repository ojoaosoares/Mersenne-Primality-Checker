# Mersenne Primality Test

## Introduction

This project implements the Lucas-Lehmer primality test to verify whether a given Mersenne number is prime. A Mersenne number is defined as:

$$
M_p = 2^p - 1
$$

where *p* is a prime number. The program takes an index  as input, checks if  is an odd prime, and, if so, applies the Lucas-Lehmer test to determine if  is prime.

## Features

- **Lucas-Lehmer Test**: Efficiently verifies the primality of Mersenne numbers.
- **Index Validation**: Ensures that the given index  is an odd prime before applying the test.
- **Optional Output**: Supports an additional flag to print the Mersenne number. However, when *p* gets bigger the respective mersenne number becomes unreadble because of its size.

## Prerequisites

### Compiler
- **C++ Compiler** (e.g., `g++`)

### Dependencies
- **GMP Library** (GNU Multiple Precision Arithmetic Library)
- **Installation Script** Run install.sh to install dependencies automatically

## How to Compile and Run

### Using Makefile

The project includes a `Makefile` to simplify the compilation process. Below are the available commands:

1. **Compile the Program**:  
To compile the program, run:
```bash
make
```

This will generate the executable in the ./bin/ folder.

2. **Clean Build Files**:
To remove all compiled object files and the executable, run:

```bash
make clean
```

### Execution

After compiling, run the program using:
```bash
./bin/mersenne_primality_test [N] [-n]
```

where [N] is the index of the Mersenne number to be tested, and the optional -n flag prints the corresponding Mersenne number.

## Program Output

- If *p* is not an odd prime, the program will output an error message
- If *p* is an odd prime, it will run the Lucas-Lehmer test and output whether  is prime.
- If the *-n* flag is provided, the program will also print the value of \( M_p\).
