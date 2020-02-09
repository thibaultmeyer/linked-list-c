#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "linkedlist.h"

void linkedlist_dump_dotgraph(s_linkedlist *linked_list, char *(*fun_render_node_data)(void *), int file_desc) {
    s_linkedlist_node *node   = linked_list->head;
    char              *buffer = NULL;
    int               len     = 0;

    write(file_desc, "digraph linkedlist {\n", 21);
    while (node != NULL) {
        if (fun_render_node_data != NULL) {
            char *data = fun_render_node_data(node->data);
            len = asprintf(&buffer, "\"%p\" [shape=box label=\"<%p>\n\n%s\"];\n", node, node, data);
            write(file_desc, buffer, len);

            free(buffer);
            if (data != NULL) {
                free(data);
            }
        } else {
            len = asprintf(&buffer, "\"%p\" [shape=box label=\"<%p>\n\n%p\"];\n", node, node, node->data);
            write(file_desc, buffer, len);

            free(buffer);
        }

        if (node->previous != NULL) {
            len = asprintf(&buffer, "\"%p\" -> \"%p\";\n", node, node->previous);
            write(file_desc, buffer, len);

            free(buffer);
        }

        if (node->next != NULL) {
            len = asprintf(&buffer, "\"%p\" -> \"%p\";\n", node, node->next);
            write(file_desc, buffer, len);

            free(buffer);
        }

        node = node->next;
    }

    write(file_desc, "}\n", 2);
}
