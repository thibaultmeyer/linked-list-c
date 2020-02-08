#include "linkedlist.h"

static inline void linkedlistnode_swap(s_linkedlist_node *n1, s_linkedlist_node *n2) {
    void *tmp = n1->data;

    n1->data = n2->data;
    n2->data = tmp;
}

void linkedlist_reverse(s_linkedlist *linked_list) {
    s_linkedlist_node *front = linked_list->head;
    s_linkedlist_node *back  = linked_list->tail;

    while (front != back) {
        linkedlistnode_swap(front, back);

        front = front->next;
        back  = back->previous;
    }
}
