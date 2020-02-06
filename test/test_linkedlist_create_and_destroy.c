#include <stdio.h>
#include "../src/linkedlist.h"

int test_linkedlist_create_and_destroy(void) {
    s_linkedlist *list;
    unsigned int size;

    // Test
    list = linkedlist_create();

    // Assert
    size = list->size;

    // Free allocated memory
    linkedlist_destroy(list, NULL);

    return size == 0;
}
