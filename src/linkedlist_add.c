#include <stdlib.h>
#include <memory.h>
#include "linkedlist.h"

int linkedlist_add(s_linkedlist *linked_list, unsigned int index, void *element) {
    s_linkedlist_node *node = linked_list->head;

    if (index == 0) {
        return linkedlist_add_front(linked_list, element);
    } else {
        while (node != NULL) {
            if (index == 0) {
                s_linkedlist_node *node_to_insert = malloc(sizeof(s_linkedlist_node));
                if (node_to_insert == NULL) {
                    return (LINKEDLIST_RETVAL_FAILURE);
                }

                memset(node_to_insert, 0, sizeof(s_linkedlist_node));

                node_to_insert->element  = element;
                node_to_insert->previous = node->previous;
                node_to_insert->next     = node;
                if (node->previous != NULL) {
                    node->previous->next = node_to_insert;
                }
                node->previous           = node_to_insert;

                linked_list->size += 1;
                return (LINKEDLIST_RETVAL_SUCCESS);
            }

            index -= 1;
            node = node->next;
        }
    }

    return (LINKEDLIST_RETVAL_FAILURE);
}
