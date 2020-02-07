#include <stdlib.h>
#include "linkedlist.h"

void *linkedlist_get_back(s_linkedlist *linked_list) {
    if (linked_list->tail != NULL) {
        return (linked_list->tail->data);
    }

    return (NULL);
}
