#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void linkedlist_dump_console(s_linkedlist *linked_list, char *(*fun_render_node_data)(void *)) {
    s_linkedlist_node *node = linked_list->head;

    printf("linkedlist<0x%p>\n", linked_list);
    while (node != NULL) {
        if (fun_render_node_data != NULL) {
            char *data = fun_render_node_data(node->data);
            printf(" + node<0x%p> = %s\n", node, data);

            if (data != NULL) {
                free(data);
            }
        } else {
            printf(" + node<0x%p> = data<0x%p>\n", node, node->data);
        }

        node = node->next;
    }
}
