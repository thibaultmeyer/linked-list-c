#include <stdlib.h>
#include "linkedlist.h"

void linkedlist_remove_if(s_linkedlist *linked_list, int (*fun_check)(void *), int (*fun_destroy)(void *)) {
    s_linkedlist_node *node      = linked_list->head;
    s_linkedlist_node *to_delete = NULL;

    while (node != NULL) {
        if (fun_check(node->data) == 1) {
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

            to_delete = node;
            node      = to_delete->next;

            if (fun_destroy != NULL) {
                fun_destroy(node->data);
            }

            free(to_delete);
            linked_list->size -= 1;
        } else {
            node = node->next;
        }
    }
}
