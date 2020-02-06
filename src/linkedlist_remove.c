#include <stdlib.h>
#include "linkedlist.h"

void *linkedlist_remove(s_linkedlist *linked_list, unsigned int index) {
    s_linkedlist_node *node = linked_list->head;

    while (node != NULL) {
        if (index == 0) {
            if (node->previous == NULL) {
                linked_list->head = node->next;
            } else {
                node->previous->next = node->next;
            }

            if (node->next == NULL) {
                linked_list->tail = node->previous;
            } else {
                node->next->previous = node->previous;
            }

            free(node);
            linked_list->size -= 1;

            return (node->data);
        }

        index -= 1;
        node = node->next;
    }

    return (NULL);
}
