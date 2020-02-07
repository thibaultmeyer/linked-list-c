#include <stdlib.h>
#include "linkedlist.h"

void *linkedlist_get_front(s_linkedlist *linked_list) {
    if (linked_list->head != NULL) {
        return (linked_list->head->data);
    }

    return (NULL);
}
