#include <stdio.h>
#include "linkedlist.h"

void *linkedlist_iterator_next(s_linkedlist_iterator *linked_list_iterator) {
    if (linked_list_iterator->current_node != NULL) {
        void *data = linked_list_iterator->current_node->data;
        linked_list_iterator->current_node = linked_list_iterator->current_node->next;

        return (data);
    }

    return (NULL);
}
