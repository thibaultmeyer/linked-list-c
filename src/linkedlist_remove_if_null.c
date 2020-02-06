#include <stdlib.h>
#include "linkedlist.h"

static int linkedlist_remove_if_null_fun_check(void *data) {
    return (data == NULL);
}

void linkedlist_remove_if_null(s_linkedlist *linked_list) {
    linkedlist_remove_if(linked_list, &linkedlist_remove_if_null_fun_check, NULL);
}
