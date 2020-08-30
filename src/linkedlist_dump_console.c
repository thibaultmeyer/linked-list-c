#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void linkedlist_dump_console(s_linkedlist *linked_list, char *(*fun_render_node_element)(void *)) {
    s_linkedlist_node *node = linked_list->head;

    printf("linkedlist<0x%p>\n", linked_list);
    while (node != NULL) {
        if (fun_render_node_element != NULL) {
            char *element = fun_render_node_element(node->element);
            printf(" + node<0x%p> = %s\n", node, element);

            if (element != NULL) {
                free(element);
            }
        } else {
            printf(" + node<0x%p> = element<0x%p>\n", node, node->element);
        }

        node = node->next;
    }
}
