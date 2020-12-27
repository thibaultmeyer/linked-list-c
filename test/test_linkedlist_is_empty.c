#include <stdio.h>
#include "../src/linkedlist.h"

int test_linkedlist_is_empty(void) {
    s_linkedlist *linked_list = NULL;
    int          test_one     = 0;
    int          test_two     = 0;
    unsigned int error        = 0;

    // Test
    linked_list = linkedlist_create();
    linkedlist_add_front(linked_list, NULL);
    test_one = linkedlist_is_empty(linked_list);
    linkedlist_remove(linked_list, 0);
    test_two = linkedlist_is_empty(linked_list);

    // Assert
    if (test_one) {
        error += 1;
    }
    if (!test_two) {
        error += 1;
    }

    // Free allocated memory
    linkedlist_destroy(linked_list, NULL);

    return (error == 0);
}
