#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include "Utilities.h"

bool IsPalindrome(const void* first, const void* const last, const size_t objectSize, int32_t (*comparator)(const void* const first, const void* const second));

void* MatchPattern(const void* first, const void* const last, const void* patternFirst, const void* const patternLast, const size_t objectSize, int32_t (*comparator)(const void* const first, const void* const second));
