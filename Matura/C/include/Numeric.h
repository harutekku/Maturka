#include <stdbool.h>
#include <math.h>
#include <errno.h>
#include <stdlib.h>
#include <stdint.h>

size_t ESieve(size_t range, uint64_t** returnValue);

int64_t Factorise(uint64_t number, uint64_t** returnValue);

uint64_t RecursiveFibonacci(uint64_t range);

uint64_t IterativeFibonacci(uint64_t range);

bool IsPrime(uint64_t number);

bool IsPerfect(uint64_t number);

long double Power(long double base, uint64_t exponent);

uint64_t RecursiveEuclidGCD(uint64_t first, uint64_t second);

uint64_t IterativeEuclidGCD(uint64_t first, uint64_t second);

long double FindRoot(long double lowerBracket, long double upperBracket, long double (*function)(long double realArg));

size_t GiveReturn(long double value, long double** returnValue);
