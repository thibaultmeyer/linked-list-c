#include <stdlib.h>
#include "linkedlist.h"

void inline linkedlist_iterator_destroy(s_linkedlist_iterator *linked_list_iterator) {
    free(linked_list_iterator);
}
