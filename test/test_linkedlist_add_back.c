#include <stdlib.h>
#include <string.h>
#include "../src/linkedlist.h"
#include "unittest.h"

static void fun_free_memory(void *element) {
    free(element);
}

int test_linkedlist_add_back(void) {
    s_linkedlist *linked_list = NULL;
    unsigned int error        = 0;

    // Test
    linked_list = linkedlist_create();
    linkedlist_add_back(linked_list, strdup("apple"));
    linkedlist_add_back(linked_list, strdup("banana"));
    linkedlist_add_back(linked_list, strdup("clementine"));
    linkedlist_add_back(linked_list, strdup("damson plum"));
    linkedlist_add_back(linked_list, strdup("elderberry"));
    linkedlist_add_back(linked_list, strdup("fig"));

    // Assert
    if (linked_list->size != 6) {
        error += 1;
    }
    if (strcmp_with_s2_nullcheck("apple", linkedlist_get(linked_list, 0)) != 0) {
        error += 1;
    }
    if (strcmp_with_s2_nullcheck("banana", linkedlist_get(linked_list, 1)) != 0) {
        error += 1;
    }
    if (strcmp_with_s2_nullcheck("clementine", linkedlist_get(linked_list, 2)) != 0) {
        error += 1;
    }
    if (strcmp_with_s2_nullcheck("damson plum", linkedlist_get(linked_list, 3)) != 0) {
        error += 1;
    }
    if (strcmp_with_s2_nullcheck("elderberry", linkedlist_get(linked_list, 4)) != 0) {
        error += 1;
    }
    if (strcmp_with_s2_nullcheck("fig", linkedlist_get(linked_list, 5)) != 0) {
        error += 1;
    }

    // Free allocated memory
    linkedlist_destroy(linked_list, &fun_free_memory);

    return (error == 0);
}
