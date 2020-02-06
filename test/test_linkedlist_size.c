#include <stdio.h>
#include "../src/linkedlist.h"

int test_linkedlist_size(void) {
    s_linkedlist *list;
    unsigned int size;

    // Test
    list = linkedlist_create();
    linkedlist_add_front(list, NULL);
    linkedlist_add_front(list, NULL);
    linkedlist_add_front(list, NULL);

    // Assert
    size = linkedlist_size(list);

    // Free allocated memory
    linkedlist_destroy(list, NULL);

    return size == 3;
}
