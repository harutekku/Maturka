#include "../include/Cipher.h"

void CaesarCipher(unsigned char* first, const unsigned char* const last, const int32_t offset) {
    for (unsigned char* i = first; i != last; ++i)
        if (*i <= 'Z' && *i >= 'A')
            *i = (*i + offset - 'A' ) % 26 + 'A';
        else if (*i <= 'z' && *i >= 'a')
            *i = (*i + offset - 'a') % 26 + 'a';
        else
            continue;
}
