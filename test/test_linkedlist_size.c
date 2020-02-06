#include <stdio.h>
#include "../src/linkedlist.h"

int test_linkedlist_size(void) {
    s_linkedlist *linked_list = NULL;
    unsigned int size         = 0;

    // Test
    linked_list = linkedlist_create();
    linkedlist_add_front(linked_list, NULL);
    linkedlist_add_front(linked_list, NULL);
    linkedlist_add_front(linked_list, NULL);

    // Assert
    size = linkedlist_size(linked_list);

    // Free allocated memory
    linkedlist_destroy(linked_list, NULL);

    return size == 3;
}
