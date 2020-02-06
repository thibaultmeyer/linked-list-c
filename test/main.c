#include <stdio.h>
#include "unittest.h"

s_linkedlist_unittest gl_unit_tests[] = {
        {"test_linkedlist_create_and_destroy", &test_linkedlist_create_and_destroy},
        {"test_linkedlist_size",               &test_linkedlist_size},
        {NULL, NULL},
};

int main(int argc, char **argv) {
    unsigned int idx = 0;
    int          ret = 0;

    while (gl_unit_tests[idx].name != NULL) {
        ret = gl_unit_tests[idx].fun_unit_test();
        printf("[%s] %s\n", ret == 1 ? "PASS" : "FAIL", gl_unit_tests[idx].name);

        idx += 1;
    }

    return (0);
}
