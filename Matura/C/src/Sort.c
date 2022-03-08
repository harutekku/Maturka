#include "../include/Sort.h"
#include "../include/Utilities.h"

int32_t Merge(void* first, void* midPoint, void* last, const size_t objectSize, int32_t (*comparator)(const void* const first, const void* const second)) {
    ptrdiff_t auxSize = Distance(first, last, objectSize);

    char* auxArray = (char*)malloc(objectSize * auxSize);
    if (!auxArray)
        return -1;

    char* i = (char*)first;
    const char* const mid = (char*)midPoint;

    char* j = (char*)midPoint;
    const char* const lastPtr = (char*)last;

    char* auxPtr = auxArray;

    while (i != mid && j != lastPtr)
        if (comparator(i, j) <= 0) {
            memcpy(auxPtr, i, objectSize);
            auxPtr += objectSize;
            i += objectSize;
        } else {
            memcpy(auxPtr, j, objectSize);
            auxPtr += objectSize;
            j += objectSize;
        }

    while (i != mid) {
        memcpy(auxPtr, i, objectSize);
        auxPtr += objectSize;
        i += objectSize;
    }

    while (j != lastPtr) {
        memcpy(auxPtr, j, objectSize);
        auxPtr += objectSize;
        j += objectSize;
    }

    memcpy(first, auxArray, objectSize * auxSize);

    free(auxArray);
    return 0;
}

void MergeSort(void* first, void* last, const size_t objectSize, int32_t (*comparator)(const void* const first, const void* const second)) {

    ptrdiff_t dist = Distance(first, last, objectSize);

    if (dist > 1) {

        char* midPoint = (char*)first + (dist / 2) * objectSize;

        MergeSort(first, midPoint, objectSize, comparator);
        MergeSort(midPoint, last, objectSize, comparator);
        if (Merge(first, midPoint, last, objectSize, comparator))
            return;
    }
}

void* Partition(void* first, void* last, const size_t objectSize, int32_t (*comparator)(const void* const first, const void* const second)) {
    char* index = (char*)first;
    char* pivot = (char*)last - objectSize;

    for (char* i = (char*)first; i != pivot; i += objectSize)
        if (comparator(i, pivot) < 0) {

            char temp[objectSize];
            memcpy(temp, i, objectSize);
            memcpy(i, index, objectSize);
            memcpy(index, temp, objectSize);

            index += objectSize;
        }
    
    char temp[objectSize];
    memcpy(temp, pivot, objectSize);
    memcpy(pivot, index, objectSize);
    memcpy(index, temp, objectSize);

    return (void*)index;
}

void QuickSort(void* first, void* last, const size_t objectSize, int32_t (*comparator)(const void* const first, const void* const second)) {

    ptrdiff_t dist = Distance(first, last, objectSize);

    if (dist < 1)
        return;

    void* i = Partition(first, last, objectSize, comparator);
    QuickSort(first, i, objectSize, comparator);
    QuickSort((char*)i + objectSize, last, objectSize, comparator);
}

void BubbleSort(void* first, void* last, const size_t objectSize, int32_t (*comparator)(const void* const first, const void* const second)) {
    bool hasSwapped = false;

    unsigned char* firstPtr = first;
    unsigned char* lastPtr = last;

    lastPtr -= objectSize; 

    do {

        hasSwapped = false;

        for (unsigned char* i = firstPtr; i != lastPtr; i += objectSize)
            if (comparator(i, i + objectSize) > 0) {
                
                unsigned char temp[objectSize];

                memcpy(temp, i, objectSize);
                memcpy(i, i + objectSize, objectSize);
                memcpy(i + objectSize, temp, objectSize);
                
                hasSwapped = true;
            }

    } while (hasSwapped);
}

void InsertionSort(void* first, void* last, const size_t objectSize, int32_t (*comparator)(const void* const first, const void* const second)) {
    unsigned char* const firstPtr = first;
    const unsigned char* const lastPtr = last;

    for (unsigned char* i = firstPtr + objectSize; i != lastPtr; i += objectSize)
        for (unsigned char* j = i; j > firstPtr && comparator(j, j - objectSize) < 0; j -= objectSize) {
            unsigned char temp[objectSize];
            memcpy(temp, j, objectSize);
            memcpy(j, j - objectSize, objectSize);
            memcpy(j - objectSize, temp, objectSize);
        }
}

void SelectionSort(void* first, void* last, const size_t objectSize, int32_t (*comparator)(const void* const first, const void* const second)) {
    unsigned char* const firstPtr = first;
    const unsigned char* const lastPtr = last;

    for (unsigned char* i = firstPtr; i != last; i += objectSize) {
        unsigned char* pivot = MinElement(i, lastPtr, objectSize, comparator);
        unsigned char temp[objectSize];
        memcpy(temp, i, objectSize);
        memcpy(i, pivot, objectSize);
        memcpy(pivot, temp, objectSize);
    }
}
