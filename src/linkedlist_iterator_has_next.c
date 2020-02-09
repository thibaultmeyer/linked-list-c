#include <stdlib.h>
#include "linkedlist.h"

int linkedlist_iterator_has_next(s_linkedlist_iterator *linked_list_iterator) {
    return linked_list_iterator->current_node != NULL;
}
