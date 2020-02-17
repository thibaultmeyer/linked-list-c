#ifndef UNITTEST_LINKEDLIST_H
# define UNITTEST_LINKEDLIST_H

typedef struct s_linkedlist_unittest s_linkedlist_unittest;

struct s_linkedlist_unittest {
    const char *name;

    int (*fun_unit_test)(void);
};

extern s_linkedlist_unittest gl_unit_tests[];

int test_linkedlist_add(void);

int test_linkedlist_apply(void);

int test_linkedlist_create_and_destroy(void);

int test_linkedlist_find(void);

int test_linkedlist_find_first(void);

int test_linkedlist_find_last(void);

int test_linkedlist_get(void);

int test_linkedlist_iterator_next(void);

int test_linkedlist_iterator_previous(void);

int test_linkedlist_remove(void);

int test_linkedlist_remove_if_null(void);

int test_linkedlist_reverse(void);

int test_linkedlist_size(void);

int test_linkedlist_sort(void);

#endif //UNITTEST_LINKEDLIST_H
