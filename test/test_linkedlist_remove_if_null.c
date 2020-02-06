#include <stdio.h>
#include "../src/linkedlist.h"

int test_linkedlist_remove_if_null(void) {
    s_linkedlist *linked_list = NULL;
    unsigned int error        = 0;

    // Test
    linked_list = linkedlist_create();
    linkedlist_add_front(linked_list, NULL);
    linkedlist_add_front(linked_list, NULL);
    linkedlist_add_front(linked_list, NULL);
    linkedlist_remove_if_null(linked_list);

    // Assert
    if (linked_list->size != 0) {
        error += 1;
    }

    if (linked_list->head != NULL) {
        error += 1;
    }

    if (linked_list->tail != NULL) {
        error += 1;
    }

    // Free allocated memory
    linkedlist_destroy(linked_list, NULL);

    return (error == 0);
}
