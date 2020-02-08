#include <stdlib.h>
#include <string.h>
#include "../src/linkedlist.h"

static void fun_free_memory(void *data) {
    free(data);
}

static void fun_applier_uppercase(void *data, void *usr_arg) {
    char *word = data;

    for (int idx = 0; word[idx] != '\0'; ++idx) {
        if (word[idx] >= 'a' && word[idx] <= 'z') {
            word[idx] -= 32;
        }
    }
}

int test_linkedlist_apply(void) {
    s_linkedlist *linked_list = NULL;
    unsigned int error        = 0;

    // Test
    linked_list = linkedlist_create();
    linkedlist_add_back(linked_list, strdup("apple"));
    linkedlist_add_back(linked_list, strdup("banana"));
    linkedlist_add_back(linked_list, strdup("clementine"));
    linkedlist_apply(linked_list, &fun_applier_uppercase, NULL);

    // Assert
    if (linked_list->size != 3) {
        error += 1;
    }
    if (strcmp("APPLE", linkedlist_get(linked_list, 0)) != 0) {
        error += 1;
    }
    if (strcmp("BANANA", linkedlist_get(linked_list, 1)) != 0) {
        error += 1;
    }
    if (strcmp("CLEMENTINE", linkedlist_get(linked_list, 2)) != 0) {
        error += 1;
    }

    // Free allocated memory
    linkedlist_destroy(linked_list, &fun_free_memory);

    return (error == 0);
}
