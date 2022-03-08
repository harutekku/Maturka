#include <stddef.h>
#include <string.h>
#include <stdint.h>


ptrdiff_t Distance(const void* first, const void* const last, const size_t objectSize);

void* MinElement(const void* first, const void* const last, const size_t objectSize, int32_t (*comparator)(const void* const first, const void* const last));

void* MaxElement(const void* first, const void* const last, const size_t objectSize, int32_t (*comparator)(const void* const first, const void* const last));

#define Swap(a, b) do {\
char temporary[(sizeof(*a) == sizeof(*b))? sizeof(*a) : -1];\
memcpy(temporary, a, sizeof(*a));\
memcpy(a, b, sizeof(*a));\
memcpy(b, temporary, sizeof(*a));\
} while (0)

