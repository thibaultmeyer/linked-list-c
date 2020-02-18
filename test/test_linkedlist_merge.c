#include <stdlib.h>
#include <string.h>
#include "../src/linkedlist.h"
#include "unittest.h"

static void fun_free_memory(void *data) {
    free(data);
}

int test_linkedlist_merge(void) {
    s_linkedlist *linked_list_one = NULL;
    s_linkedlist *linked_list_two = NULL;
    unsigned int error            = 0;

    // Test
    linked_list_one = linkedlist_create();
    linked_list_two = linkedlist_create();
    linkedlist_add_back(linked_list_one, strdup("apple"));
    linkedlist_add_back(linked_list_one, strdup("banana"));
    linkedlist_add_back(linked_list_two, strdup("durian"));
    linkedlist_add_back(linked_list_two, strdup("feijoa"));
    linkedlist_merge(linked_list_one, linked_list_two);

    // Assert
    if (strcmp_with_s2_nullcheck("apple", linkedlist_get(linked_list_one, 0)) != 0) {
        error += 1;
    }
    if (strcmp_with_s2_nullcheck("banana", linkedlist_get(linked_list_one, 1)) != 0) {
        error += 1;
    }
    if (strcmp_with_s2_nullcheck("durian", linkedlist_get(linked_list_one, 2)) != 0) {
        error += 1;
    }
    if (strcmp_with_s2_nullcheck("feijoa", linkedlist_get(linked_list_one, 3)) != 0) {
        error += 1;
    }

    // Free allocated memory
    linkedlist_destroy(linked_list_one, &fun_free_memory);
    linkedlist_destroy(linked_list_two, NULL);

    return (error == 0);
}
