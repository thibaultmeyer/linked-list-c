#include <stdlib.h>
#include "linkedlist.h"

static inline void linkedlistnode_swap(s_linkedlist_node *n1, s_linkedlist_node *n2) {
    void *tmp = n1->element;

    n1->element = n2->element;
    n2->element = tmp;
}

void linkedlist_sort(s_linkedlist *linked_list, f_comparator comparator) {
    s_linkedlist_node *node   = NULL;
    s_linkedlist_node *lptr   = NULL;
    int               swapped = 0;

    do {
        node    = linked_list->head;
        swapped = 0;

        while (node->next != lptr) {
            if (comparator(node->element, node->next->element) > 0) {
                linkedlistnode_swap(node, node->next);
                swapped = 1;
            }

            node = node->next;
        }

        lptr = node;
    } while (swapped);
}
