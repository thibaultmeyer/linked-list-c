#include <stdlib.h>
#include "linkedlist.h"

void linkedlist_apply(s_linkedlist *linked_list, f_applier applier, void *applier_arg) {
    s_linkedlist_node *node = linked_list->head;

    while (node != NULL) {
        applier(node->element, applier_arg);

        node = node->next;
    }
}
