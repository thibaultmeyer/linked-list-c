#include <string.h>

int strcmp_with_s2_nullcheck(const char *s1, const char *s2) {
    if (s2 == NULL && s1 != s2) {
        return -1;
    }

    return strcmp(s1, s2);
}
