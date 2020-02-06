#include <stdlib.h>
#include <memory.h>
#include "linkedlist.h"

s_linkedlist *linkedlist_create(void) {
    s_linkedlist *linked_list = malloc(sizeof(s_linkedlist));
    memset(linked_list, 0, sizeof(s_linkedlist));

    return (linked_list);
}
