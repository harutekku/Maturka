#include "Utilities.h"
#include <stdint.h>

void* BinarySearch(const void* first, const void* const last, const void* const what, const size_t objSize, int32_t (*comparator)(const void* const left, const void* const right));

void* LinearSearch(const void* first, const void* const last, const void* const what, const size_t objSize, int32_t (*comparator)(const void* const left, const void* const right));
