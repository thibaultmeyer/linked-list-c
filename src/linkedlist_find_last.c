#include <stdlib.h>
#include "linkedlist.h"

void *linkedlist_find_last(s_linkedlist *linked_list, f_matcher matcher, void *matcher_arg) {
    s_linkedlist_node *node = linked_list->tail;

    while (node != NULL) {
        if (matcher(node->element, matcher_arg) == E_MATCHER_RESULT_MATCH) {
            return node->element;
        }

        node = node->previous;
    }

    return NULL;
}
