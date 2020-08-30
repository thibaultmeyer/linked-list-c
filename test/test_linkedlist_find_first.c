#include <stdlib.h>
#include <string.h>
#include "../src/linkedlist.h"
#include "unittest.h"

static void fun_free_memory(void *element) {
    free(element);
}

static e_matcher_result fun_matcher_len_six(void *element_left, void *element_right) {
    return strlen(element_left) == 6 ? E_MATCHER_RESULT_MATCH : E_MATCHER_RESULT_NOT_MATCH;
}

int test_linkedlist_find_first(void) {
    s_linkedlist *linked_list = NULL;
    void         *element     = NULL;
    unsigned int error        = 0;

    // Test
    linked_list = linkedlist_create();
    linkedlist_add_back(linked_list, strdup("apple"));
    linkedlist_add_back(linked_list, strdup("banana"));
    linkedlist_add_back(linked_list, strdup("durian"));
    linkedlist_add_back(linked_list, strdup("feijoa"));
    element = linkedlist_find_first(linked_list, &fun_matcher_len_six, NULL);

    // Assert
    if (strcmp_with_s2_nullcheck("banana", element) != 0) {
        error += 1;
    }

    // Free allocated memory
    linkedlist_destroy(linked_list, &fun_free_memory);

    return (error == 0);
}
