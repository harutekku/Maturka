#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

int32_t Merge(void* first, void* MidPoint, void* last, const size_t objectSize, int32_t (*comparator)(const void* const first, const void* const second));

void MergeSort(void* first, void* last,  const size_t objectSize, int32_t (*comparator)(const void* const first, const void* const second));

void* Partition(void* first, void* last,  const size_t objectSize, int32_t (*comparator)(const void* const first, const void* const second));

void QuickSort(void* first, void* last,  const size_t objectSize, int32_t (*comparator)(const void* const first, const void* const second));

void BubbleSort(void* first, void* last,  const size_t objectSize, int32_t (*comparator)(const void* const first, const void* const second));

void InsertionSort(void* first, void* last,  const size_t objectSize, int32_t (*comparator)(const void* const first, const void* const second));

void SelectionSort(void* first, void* last,  const size_t objectSize, int32_t (*comparator)(const void* const first, const void* const second));
