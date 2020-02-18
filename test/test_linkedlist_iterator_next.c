#include <stdlib.h>
#include <string.h>
#include "../src/linkedlist.h"
#include "unittest.h"

static void fun_free_memory(void *data) {
    free(data);
}

int test_linkedlist_iterator_next(void) {
    s_linkedlist          *linked_list          = NULL;
    s_linkedlist_iterator *linked_list_iterator = NULL;
    void                  *data                 = NULL;
    unsigned int          error                 = 0;

    // Prepare data for test
    linked_list = linkedlist_create();
    linkedlist_add_back(linked_list, strdup("apple"));
    linkedlist_add_back(linked_list, strdup("banana"));
    linkedlist_add_back(linked_list, strdup("clementine"));
    linked_list_iterator = linkedlist_iterator_create(linked_list);

    if (linkedlist_iterator_has_next(linked_list_iterator) == 1) {
        data = linkedlist_iterator_next(linked_list_iterator);

        if (strcmp_with_s2_nullcheck("apple", data) != 0) {
            error += 1;
        }
    } else {
        error += 1;
    }

    if (linkedlist_iterator_has_next(linked_list_iterator) == 1) {
        data = linkedlist_iterator_next(linked_list_iterator);

        if (strcmp_with_s2_nullcheck("banana", data) != 0) {
            error += 1;
        }
    } else {
        error += 1;
    }

    if (linkedlist_iterator_has_next(linked_list_iterator) == 1) {
        data = linkedlist_iterator_next(linked_list_iterator);

        if (strcmp_with_s2_nullcheck("clementine", data) != 0) {
            error += 1;
        }
    } else {
        error += 1;
    }

    if (linkedlist_iterator_has_next(linked_list_iterator) == 1) {
        error += 1;
    }

    // Free allocated memory
    linkedlist_iterator_destroy(linked_list_iterator);
    linkedlist_destroy(linked_list, &fun_free_memory);

    return (error == 0);
}
