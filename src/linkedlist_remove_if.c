#include <stdlib.h>
#include "linkedlist.h"

void linkedlist_remove_if(s_linkedlist *linked_list, f_matcher matcher, void *matcher_arg, f_destroy_data destroy_data) {
    s_linkedlist_node *node      = linked_list->head;
    s_linkedlist_node *to_delete = NULL;

    while (node != NULL) {
        if (matcher(node->data, matcher_arg) == E_MATCHER_RESULT_MATCH) {
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

            if (destroy_data != NULL) {
                destroy_data(node->data);
            }

            free(to_delete);
            linked_list->size -= 1;
        } else {
            node = node->next;
        }
    }
}
