#include <stdlib.h>
#include "linkedlist.h"

int linkedlist_merge(s_linkedlist *linked_list_to, s_linkedlist *linked_list_to_from) {
    s_linkedlist      *linked_list_tmp      = linkedlist_create();
    s_linkedlist_node *linked_list_node_tmp = linked_list_to_from->head;

    if (linked_list_tmp == NULL) {
        return (LINKEDLIST_RETVAL_FAILURE);
    }

    while (linked_list_node_tmp != NULL) {
        if (linkedlist_add_back(linked_list_tmp, linked_list_node_tmp->data) == LINKEDLIST_RETVAL_FAILURE) {
            linkedlist_destroy(linked_list_tmp, NULL);

            return (LINKEDLIST_RETVAL_FAILURE);
        }

        linked_list_node_tmp = linked_list_node_tmp->next;
    }

    linked_list_to->tail->next = linked_list_tmp->head;
    linked_list_to->size += linked_list_tmp->size;
    free(linked_list_tmp);

    return (LINKEDLIST_RETVAL_SUCCESS);
}
