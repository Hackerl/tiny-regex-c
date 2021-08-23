/*

This file tests two bug patterns reported by @DavidKorczynski in https://github.com/kokke/tiny-regex-c/issues/44

*/

#include <assert.h>
#include <stdlib.h> /* for NULL */
#include "re.h"


int main() {
    regex_t re_compiled[MAX_REGEXP_OBJECTS];
    unsigned char ccl_buf[MAX_CHAR_CLASS_LEN];

    /* Test 1: inverted set without a closing ']' */
    assert(re_compile("\\\x01[^\\\xff][^", re_compiled, ccl_buf) == NULL);

    /* Test 2: set with an incomplete escape sequence and without a closing ']' */
    assert(re_compile("\\\x01[^\\\xff][\\", re_compiled, ccl_buf) == NULL);

    return 0;
}

