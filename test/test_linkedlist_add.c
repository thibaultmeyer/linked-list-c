#include <stdlib.h>
#include <string.h>
#include "../src/linkedlist.h"

static void fun_free_memory(void *data) {
    free(data);
}

int test_linkedlist_add(void) {
    s_linkedlist *linked_list = NULL;
    unsigned int error        = 0;

    // Test
    linked_list = linkedlist_create();
    linkedlist_add(linked_list, 0, strdup("apple"));
    linkedlist_add(linked_list, 0, strdup("banana"));
    linkedlist_add(linked_list, 1, strdup("clementine"));
    linkedlist_add(linked_list, 2, strdup("damson plum"));
    linkedlist_add(linked_list, 3, strdup("elderberry"));
    linkedlist_add(linked_list, 4, strdup("fig"));

    // Assert
    if (linked_list->size != 6) {
        error += 1;
    }
    if (strcmp("apple", linkedlist_get(linked_list, 5)) != 0) {
        error += 1;
    }
    if (strcmp("banana", linkedlist_get(linked_list, 0)) != 0) {
        error += 1;
    }
    if (strcmp("clementine", linkedlist_get(linked_list, 1)) != 0) {
        error += 1;
    }
    if (strcmp("damson plum", linkedlist_get(linked_list, 2)) != 0) {
        error += 1;
    }
    if (strcmp("elderberry", linkedlist_get(linked_list, 3)) != 0) {
        error += 1;
    }
    if (strcmp("fig", linkedlist_get(linked_list, 4)) != 0) {
        error += 1;
    }

    // Free allocated memory
    linkedlist_destroy(linked_list, &fun_free_memory);

    return (error == 0);
}
