#include <stdlib.h>
#include <string.h>
#include "../src/linkedlist.h"

static void fun_free_memory(void *data) {
    free(data);
}

static e_matcher_result fun_matcher_len_six(void *data_left, void *data_right) {
    return strlen(data_left) == 6 ? E_MATCHER_RESULT_MATCH : E_MATCHER_RESULT_NOT_MATCH;
}

int test_linkedlist_find_first(void) {
    s_linkedlist *linked_list = NULL;
    void         *data        = NULL;
    unsigned int error        = 0;

    // Test
    linked_list = linkedlist_create();
    linkedlist_add_back(linked_list, strdup("apple"));
    linkedlist_add_back(linked_list, strdup("banana"));
    linkedlist_add_back(linked_list, strdup("durian"));
    linkedlist_add_back(linked_list, strdup("feijoa"));
    data = linkedlist_find_first(linked_list, &fun_matcher_len_six, NULL);

    // Assert
    if (strcmp("banana", data) != 0) {
        error += 1;
    }

    // Free allocated memory
    linkedlist_destroy(linked_list, &fun_free_memory);

    return (error == 0);
}
