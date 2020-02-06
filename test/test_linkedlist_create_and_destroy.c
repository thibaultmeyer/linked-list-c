#include <stdio.h>
#include "../src/linkedlist.h"

int test_linkedlist_create_and_destroy(void) {
    s_linkedlist *linked_list = NULL;
    unsigned int size         = 0;

    // Test
    linked_list = linkedlist_create();

    // Assert
    size = linked_list->size;

    // Free allocated memory
    linkedlist_destroy(linked_list, NULL);

    return (size == 0);
}
