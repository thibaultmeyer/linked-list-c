#include <stdio.h>
#include "unittest.h"

s_linkedlist_unittest gl_unit_tests[] = {
        {"test_linkedlist_create_and_destroy", &test_linkedlist_create_and_destroy},
        {"test_linkedlist_size",               &test_linkedlist_size},
        {NULL, NULL},
};

int main(int argc, char **argv) {
    unsigned int idx           = 0;
    int          ret           = 0;
    int          success_count = 0;
    int          error_count   = 0;

    while (gl_unit_tests[idx].name != NULL) {
        ret = gl_unit_tests[idx].fun_unit_test();
        printf("[%s] %s\n", ret == 1 ? "PASS" : "FAIL", gl_unit_tests[idx].name);

        if (ret == 1) {
            success_count += 1;
        } else {
            error_count += 1;
        }

        idx += 1;
    }

    return (error_count);
}
