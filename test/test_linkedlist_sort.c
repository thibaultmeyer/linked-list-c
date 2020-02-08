#include <stdlib.h>
#include <string.h>
#include "../src/linkedlist.h"

static void fun_free_memory(void *data) {
    free(data);
}

static int fun_comparator_sort_ascending(void *data_left, void *data_right) {
    return strcmp(data_left, data_right);
}

int test_linkedlist_sort(void) {
    s_linkedlist *linked_list = NULL;
    unsigned int error        = 0;

    // Test
    linked_list = linkedlist_create();
    linkedlist_add_back(linked_list, strdup("banana"));
    linkedlist_add_back(linked_list, strdup("apple"));
    linkedlist_add_back(linked_list, strdup("clementine"));
    linkedlist_sort(linked_list, &fun_comparator_sort_ascending);

    // Assert
    if (linked_list->size != 3) {
        error += 1;
    }
    if (strcmp("apple", linkedlist_get(linked_list, 0)) != 0) {
        error += 1;
    }
    if (strcmp("banana", linkedlist_get(linked_list, 1)) != 0) {
        error += 1;
    }
    if (strcmp("clementine", linkedlist_get(linked_list, 2)) != 0) {
        error += 1;
    }

    // Free allocated memory
    linkedlist_destroy(linked_list, &fun_free_memory);

    return (error == 0);
}
