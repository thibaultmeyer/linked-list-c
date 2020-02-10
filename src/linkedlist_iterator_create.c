#include <stdlib.h>
#include <memory.h>
#include "linkedlist.h"

s_linkedlist_iterator *linkedlist_iterator_create(s_linkedlist *linked_list) {
    s_linkedlist_iterator *linked_list_iterator = malloc(sizeof(s_linkedlist_iterator));

    if (linked_list_iterator != NULL) {
        memset(linked_list_iterator, 0, sizeof(s_linkedlist_iterator));
        linked_list_iterator->current_node = linked_list->head;
    }

    return (linked_list_iterator);
}
