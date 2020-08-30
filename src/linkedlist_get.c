#include <stdlib.h>
#include "linkedlist.h"

void *linkedlist_get(s_linkedlist *linked_list, unsigned int index) {
    s_linkedlist_node *node = linked_list->head;

    while (node != NULL) {
        if (index == 0) {
            return (node->element);
        }

        index -= 1;
        node = node->next;
    }

    return (NULL);
}
