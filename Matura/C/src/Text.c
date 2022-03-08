#include "../include/Text.h"

bool IsPalindrome(const void* first, const void* const last, const size_t objectSize, int32_t (*comparator)(const void* const first, const void* const second)) {
    const unsigned char* firstPtr = first;
    const unsigned char* lastPtr = last;

    while (firstPtr < lastPtr)
        if (comparator(firstPtr, lastPtr - objectSize) != 0)
            return false;
        else {
            firstPtr += objectSize;
            lastPtr -= objectSize;
        }

    return true;
}

void* MatchPattern(const void* first, const void* const last, const void* patternFirst, const void* const patternLast, const size_t objectSize, int32_t (*comparator)(const void* const first, const void* const second)) {
    
    ptrdiff_t rangeSize = Distance(first, last, objectSize);
    ptrdiff_t patternSize = Distance(patternFirst, patternLast, objectSize);

    if (rangeSize < patternSize)
        return NULL;
    

    const unsigned char* firstPtr = first;
    const unsigned char* const lastPtr = last;
    const unsigned char* patternFirstPtr = patternFirst;
    const unsigned char* const patternLastPtr = patternLast;

    for (const unsigned char* i = firstPtr; i != lastPtr; i += objectSize)
        if (comparator(i, patternFirstPtr) == 0) {
            const unsigned char* const occurence = i;
            const unsigned char* tempI = i;
            const unsigned char* j = patternFirstPtr;
            for (; tempI != lastPtr && j != patternLastPtr && comparator(j, tempI) == 0; j += objectSize, tempI += objectSize);

            if (j == patternLastPtr)
                return (void*)occurence;
        }
    
    return (void*)last;
}

