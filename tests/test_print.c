/*
    This program prints out a verbose explanation of a given regular expression.
*/

#include <stdio.h>
#include "re.h"


int main(int argc, char **argv) {
    regex_t re_compiled[MAX_REGEXP_OBJECTS];
    unsigned char ccl_buf[MAX_CHAR_CLASS_LEN];

    if (argc == 2) {
        re_print(re_compile(argv[1], re_compiled, ccl_buf));
    } else {
        printf("\nUsage: %s <PATTERN> \n", argv[0]);
    }
    return -2;
}
