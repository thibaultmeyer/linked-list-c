#include <stdlib.h>
#include "linkedlist.h"

static e_matcher_result linkedlist_remove_if_null_fun_matcher(void *data, void *matcher_arg) {
    return (data == NULL ? E_MATCHER_RESULT_MATCH : E_MATCHER_RESULT_NOT_MATCH);
}

void linkedlist_remove_if_null(s_linkedlist *linked_list) {
    linkedlist_remove_if(linked_list, &linkedlist_remove_if_null_fun_matcher, NULL, NULL);
}
