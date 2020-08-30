#include <stdlib.h>
#include "linkedlist.h"

s_linkedlist *linkedlist_find(s_linkedlist *linked_list, f_matcher matcher, void *matcher_arg) {
    s_linkedlist_node *node               = linked_list->head;
    s_linkedlist      *linked_list_result = linkedlist_create();

    if (linked_list_result == NULL) {
        return NULL;
    }

    while (node != NULL) {
        if (matcher(node->element, matcher_arg) == E_MATCHER_RESULT_MATCH) {
            linkedlist_add_back(linked_list_result, node->element);
        }

        node = node->next;
    }

    return linked_list_result;
}
