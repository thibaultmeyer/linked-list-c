#include <stdio.h>
#include "../src/linkedlist.h"

int test_linkedlist_size(void) {
    s_linkedlist *linked_list = NULL;
    unsigned int size_one     = 0;
    unsigned int size_two     = 0;
    unsigned int error        = 0;

    // Test
    linked_list = linkedlist_create();
    linkedlist_add_front(linked_list, NULL);
    linkedlist_add_front(linked_list, NULL);
    linkedlist_add_front(linked_list, NULL);
    size_one = linkedlist_size(linked_list);
    linkedlist_remove(linked_list, 0);
    size_two = linkedlist_size(linked_list);

    // Assert
    if (size_one != 3) {
        error += 1;
    }
    if (size_two != 2) {
        error += 1;
    }

    // Free allocated memory
    linkedlist_destroy(linked_list, NULL);

    return (error == 0);
}
