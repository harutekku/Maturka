#include "../include/Search.h"

void* BinarySearch(const void* first, const void* const last, const void* const what, const size_t objSize, int32_t (*comparator)(const void* const left, const void* const right)) {
    const unsigned char* firstPtr = first;
    const unsigned char* lastPtr = last;

    lastPtr -= objSize;
    

    while (firstPtr < lastPtr) {
        ptrdiff_t midPoint = Distance(firstPtr, lastPtr, objSize) / 2;
        if (comparator(firstPtr + midPoint * objSize, what) < 0)
            firstPtr = firstPtr + (midPoint + 1) * objSize;
        else
            lastPtr = firstPtr + midPoint * objSize;
    }

    return (void*)firstPtr;
}

void* LinearSearch(const void* first, const void* const last, const void* const what, const size_t objSize, int32_t (*comparator)(const void* const left, const void* const right)) {
    const unsigned char* firstPtr = first;
    const unsigned char* const lastPtr = last;

    for (; firstPtr != lastPtr; firstPtr += objSize)
        if (comparator(firstPtr, what) == 0)
            break;
    return (void*)firstPtr;
}

