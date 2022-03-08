#include "../include/Utilities.h"

ptrdiff_t Distance(const void* first, const void* const last, const size_t objectSize) {
    const unsigned char* firstPtr = first;
    const unsigned char* lastPtr = last;

    ptrdiff_t distance = 0u;

    while (firstPtr < lastPtr) {
        firstPtr += objectSize;
        ++distance;
    }
    return distance;
}

void* MinElement(const void* first, const void* const last, const size_t objectSize, int32_t (*comparator)(const void* const first, const void* const last)) {
    const unsigned char* const firstPtr = first;
    const unsigned char* const lastPtr = last;

    const unsigned char* retVal = firstPtr;

    for (const unsigned char* i = firstPtr + objectSize; i != lastPtr; i += objectSize)
        if (comparator(retVal, i) > 0)
            retVal = i;
    return (void*)retVal;
}

void* MaxElement(const void* first, const void* const last, const size_t objectSize, int32_t (*comparator)(const void* const first, const void* const last)) {
    const unsigned char* const firstPtr = first;
    const unsigned char* const lastPtr = last;

    const unsigned char* retVal = firstPtr;

    for (const unsigned char* i = firstPtr + objectSize; i != lastPtr; i += objectSize)
        if (comparator(retVal, i) < 0)
            retVal = i;
    return (void*)retVal;
}
