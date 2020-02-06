#include <stdlib.h>
#include "linkedlist.h"

void linkedlist_destroy(s_linkedlist *linked_list, void (*fun_on_each)(void *item)) {
    s_linkedlist_node *current_entry = linked_list->head;
    s_linkedlist_node *to_delete     = NULL;

    while (current_entry != 0) {
        if (current_entry->data != NULL && fun_on_each != NULL) {
            fun_on_each(current_entry->data);
        }

        to_delete     = current_entry;
        current_entry = current_entry->next;

        free(to_delete);
    }

    free(linked_list);
}
