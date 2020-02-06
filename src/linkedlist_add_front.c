#include <stdlib.h>
#include <memory.h>
#include "linkedlist.h"

void linkedlist_add_front(s_linkedlist *linked_list, void *data) {
    s_linkedlist_node *node = malloc(sizeof(s_linkedlist_node));
    memset(node, 0, sizeof(s_linkedlist_node));

    node->data = data;

    if (linked_list->head == NULL) {
        linked_list->head = node;
    } else {
        node->next                  = linked_list->head;
        linked_list->head->previous = node;
        linked_list->head           = node;
    }

    if (linked_list->tail == NULL) {
        linked_list->tail = node;
    }

    linked_list->size += 1;
}
