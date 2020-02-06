#include <stdlib.h>
#include <memory.h>
#include "linkedlist.h"

void linkedlist_add_back(s_linkedlist *linked_list, void *data) {
    s_linkedlist_node *node = malloc(sizeof(s_linkedlist_node));
    memset(node, 0, sizeof(s_linkedlist_node));

    node->data = data;

    if (linked_list->tail == NULL) {
        linked_list->tail = node;
    } else {
        node->previous       = linked_list->tail;
        node->previous->next = node;
        linked_list->tail    = node;
    }

    if (linked_list->head == NULL) {
        linked_list->head = node;
    }

    linked_list->size += 1;
}
