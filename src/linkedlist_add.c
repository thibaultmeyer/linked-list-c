#include <stdlib.h>
#include <memory.h>
#include "linkedlist.h"

void linkedlist_add(s_linkedlist *linked_list, unsigned int index, void *data) {
    s_linkedlist_node *node = linked_list->head;

    if (index == 0) {
        linkedlist_add_front(linked_list, data);
    } else {
        while (node != NULL) {
            if (index == 0) {
                s_linkedlist_node *node_to_insert = malloc(sizeof(s_linkedlist_node));
                memset(node_to_insert, 0, sizeof(s_linkedlist_node));

                node_to_insert->data     = data;
                node_to_insert->previous = node->previous;
                node_to_insert->next     = node;
                if (node->previous != NULL) {
                    node->previous->next = node_to_insert;
                }
                node->previous           = node_to_insert;

                linked_list->size += 1;
                break;
            }

            index -= 1;
            node = node->next;
        }
    }
}
