#include "../include/Numeric.h"

size_t ESieve(size_t range, uint64_t** returnValue) {
    if (range < 2 || !returnValue) 
        return 0;
    bool* primesPoll = (bool*)malloc(range * sizeof(bool));

    if (!primesPoll)
        return 0;

    const size_t rangeSqrt = sqrt(range);

    for (size_t i = 2u; i < range; ++i)
        primesPoll[i] = true;

    for (size_t i = 2u; i < rangeSqrt; ++i)
        if (primesPoll[i])
            for (size_t j = 2 * i; j < range; j += i)
                primesPoll[j] = false;

    size_t retValSize = 0u;
    uint64_t* temp = (uint64_t*)malloc(sizeof(uint64_t) * range);
    if (!temp) {
        free(primesPoll);
        return 0;
    } else
        *returnValue = temp;

    for (size_t i = 2u; i < range; ++i)
        if (primesPoll[i])
            (*returnValue)[retValSize++] = i;

    temp = realloc(*returnValue, retValSize * sizeof(uint64_t));
    if (!temp) {
        free(primesPoll);
        free(*returnValue);
        return 0;
    } else
        *returnValue = temp;
    free(primesPoll);
    return retValSize;
}

int64_t Factorise(uint64_t number, uint64_t ** returnValue) {
    if (!number || !returnValue)
        return -1;

    size_t retValSize = 8u;
    uint64_t* temp = NULL;
    *returnValue = malloc(sizeof(uint64_t) * retValSize);

    if (!(*returnValue))
        return -1;

    const size_t range = sqrt(number);

    uint64_t i = 2u;
    size_t j = 0u;

    while (i <= range)
        if (!(number % i)) {
            number /= i;

            if (j != retValSize)
                (*returnValue)[j++] = i;
            else {
                temp = realloc(*returnValue, (retValSize * 2) * sizeof(uint64_t));
                if (!temp) {
                    free(*returnValue);
                    return -1;
                } else
                    *returnValue = temp;

                retValSize *= 2;
                (*returnValue)[j++] = i;
            }
        } else
            ++i;

    if (j != retValSize)
        (*returnValue)[j++] = number;
    else {
        temp = realloc(*returnValue, (retValSize + 1) * sizeof(uint64_t));
        if (!temp) {
            free(*returnValue);
            return -1;
        } else
            *returnValue = temp;
        ++retValSize;
        (*returnValue)[j++] = number;
    }

    temp = realloc(*returnValue, j * sizeof(uint64_t));
    if (!temp) {
        free(*returnValue);
        return -1;
    } else 
        *returnValue = temp;
    
    return (int64_t)j;
}

uint64_t RecursiveFibonacci(uint64_t range) {
    if (range <= 1)
        return range;
    else
        return RecursiveFibonacci(range - 1) + RecursiveFibonacci(range - 2);
}

uint64_t IterativeFibonacci(uint64_t range) {
    uint64_t oldValue = 0u;
    uint64_t currentValue = 1u;

    for (uint64_t i = 1u; i != range; ++i) {
        uint64_t temp = currentValue;
        currentValue += oldValue;
        oldValue = temp;
    }

    return currentValue;
}

bool IsPrime(uint64_t number) {
    if (number % 2 == 0 && number > 2)
        return false;
    else if (number % 3 == 0 && number > 3)
        return false;
    
    const uint64_t range = sqrt(number);

    uint64_t i = 5;

    while (i <= range)
        if (number % i == 0)
            return false;
        else if (number % (i + 2) == 0)
            return false;
        else
            i += 6;
    
    return true;
}

bool IsPerfect(uint64_t number) {
    const uint64_t range = sqrt(number);
    uint64_t sum = 1;

    for (uint64_t i = 2u; i <= range; ++i)
        if (number % i == 0)
            sum += number / i + i;

    if (range * range == number)
        sum -= range;

    if (sum == number)
        return true;
    else
        return false;
}

long double Power(long double base, uint64_t exponent) {
    if (exponent == 0)
        return 1;
    else if (exponent % 2 == 1)
        return base * Power(base, exponent - 1);
    else {
        long double retVal = Power(base, exponent / 2);
        return retVal * retVal;
    }
}

uint64_t RecursiveEuclidGCD(uint64_t first, uint64_t second) {
    if (first % second == 0)
        return second;
    else
        return RecursiveEuclidGCD(second, first % second);
}

uint64_t IterativeEuclidGCD(uint64_t first, uint64_t second) {
    uint64_t ray = 0u;

    while (second != 0) {
        ray = first % second;
        first = second;
        second = ray;
    }

    return first;
}

long double FindRoot(long double lowerBracket, long double upperBracket, long double (*function)(long double realArg)) {
    const long double epsilon = 0.000000000000001l;

    if (!function || function(lowerBracket) * function(upperBracket) > 0) {
        return 0;
    }

    long double midPoint = 0u;

    while (fabsl(upperBracket - lowerBracket) > epsilon) {
        midPoint = (lowerBracket + upperBracket) / 2;
        const long double valueAtMidPoint = function(midPoint);

        if (fabsl(valueAtMidPoint) < epsilon)
            return midPoint;
        else if (function(lowerBracket) * valueAtMidPoint < 0)
            upperBracket = midPoint;
        else
            lowerBracket = midPoint;
    }

    return midPoint;
}

size_t GiveReturn(long double value, long double** returnValue) {
    if (value < 0 || !returnValue) 
        return 0;

    static const uint32_t nominals[] = { 1u, 2u, 5u, 10u, 20u, 50u, 100u, 200u, 500u, 1000u, 2000u, 5000u, 10000u, 20000u, 50000u };
    uint64_t actualValue = (size_t)(value * 100);

    size_t retValSize = 8u;
    size_t retValIndex = 0u;
    long double* temp = malloc(sizeof(long double) * retValSize);
    
    if (!temp) 
        return 0;
    else
        *returnValue = temp;

    while (actualValue != 0) {
        uint32_t nominal = 0u;

        for (size_t i = 0; i != 15; ++i)
            if (nominals[i] <= actualValue && nominals[i] > nominal)
                nominal = nominals[i];

        if (retValIndex != retValSize)
            (*returnValue)[retValIndex++] = nominal / 100.0l;
        else {
            retValSize *= 2;
            temp = realloc(*returnValue, retValSize * sizeof(long double));
            if (!temp) {
                free(*returnValue);
                return 0;
            } else
                *returnValue = temp;
            (*returnValue)[retValIndex++] = nominal / 100.0l;
        }
        actualValue -= nominal;
    }

    temp = realloc(*returnValue, retValIndex * sizeof(long double));

    if (!temp) {
        free(*returnValue);
        return 0;
    } else
        *returnValue = temp;

    return retValIndex;
}

