#include <stdio.h>
#include "../src/linkedlist.h"

int test_linkedlist_remove(void) {
    s_linkedlist *linked_list = NULL;
    unsigned int error        = 0;

    // Test
    linked_list = linkedlist_create();
    linkedlist_add_front(linked_list, NULL);
    linkedlist_add_front(linked_list, NULL);
    linkedlist_add_front(linked_list, NULL);
    linkedlist_remove(linked_list, 1);

    // Assert
    if (linked_list->size != 2) {
        error += 1;
    }

    if (linked_list->head->next != linked_list->tail) {
        error += 1;
    }

    if (linked_list->head->next->previous != linked_list->head) {
        error += 1;
    }

    // Free allocated memory
    linkedlist_destroy(linked_list, NULL);

    return (error == 0);
}
