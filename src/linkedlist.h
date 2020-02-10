#ifndef LINKEDLIST_H
# define LINKEDLIST_H
# define LINKEDLIST_RETVAL_SUCCESS 0
# define LINKEDLIST_RETVAL_FAILURE -1

typedef struct s_linkedlist_iterator s_linkedlist_iterator;
typedef struct s_linkedlist_node     s_linkedlist_node;
typedef struct s_linkedlist          s_linkedlist;
typedef enum e_matcher_result        e_matcher_result;

typedef void             (*f_applier)(void *data, void *usr_arg);

typedef int              (*f_comparator)(void *data_left, void *data_right);

typedef int              (*f_destroy_data)(void *data);

typedef e_matcher_result (*f_matcher)(void *data, void *usr_arg);

struct s_linkedlist_iterator {
    s_linkedlist_node *current_node;
};

struct s_linkedlist_node {
    s_linkedlist_node *previous;
    s_linkedlist_node *next;
    void              *data;
};

struct s_linkedlist {
    unsigned int      size;
    s_linkedlist_node *head;
    s_linkedlist_node *tail;
};

enum e_matcher_result {
    E_MATCHER_RESULT_NOT_MATCH = 0,
    E_MATCHER_RESULT_MATCH     = 1
};

int linkedlist_add(s_linkedlist *linked_list, unsigned int index, void *data);

int linkedlist_add_back(s_linkedlist *linked_list, void *data);

int linkedlist_add_front(s_linkedlist *linked_list, void *data);

void linkedlist_apply(s_linkedlist *linked_list, f_applier applier, void *applier_arg);

s_linkedlist *linkedlist_create(void);

void linkedlist_destroy(s_linkedlist *linked_list, void (*fun_on_each)(void *item));

void linkedlist_dump_console(s_linkedlist *linked_list, char *(*fun_render_node_data)(void *data));

void linkedlist_dump_dotgraph(s_linkedlist *linked_list, char *(*fun_render_node_data)(void *data), int file_desc);

void *linkedlist_find_first(s_linkedlist *linked_list, f_matcher matcher, void *matcher_arg);

void *linkedlist_find_last(s_linkedlist *linked_list, f_matcher matcher, void *matcher_arg);

void *linkedlist_get(s_linkedlist *linked_list, unsigned int index);

void *linkedlist_get_back(s_linkedlist *linked_list);

void *linkedlist_get_front(s_linkedlist *linked_list);

s_linkedlist_iterator *linkedlist_iterator_create(s_linkedlist *linked_list);

void linkedlist_iterator_destroy(s_linkedlist_iterator *linked_list_iterator);

int linkedlist_iterator_has_next(s_linkedlist_iterator *linked_list_iterator);

void *linkedlist_iterator_next(s_linkedlist_iterator *linked_list_iterator);

void *linkedlist_remove(s_linkedlist *linked_list, unsigned int index);

void linkedlist_remove_if(s_linkedlist *linked_list, f_matcher matcher, void *matcher_arg, f_destroy_data destroy_data);

void linkedlist_remove_if_null(s_linkedlist *linked_list);

void linkedlist_reverse(s_linkedlist *linked_list);

unsigned int linkedlist_size(s_linkedlist *linked_list);

void linkedlist_sort(s_linkedlist *linked_list, f_comparator comparator);

#endif //LINKEDLIST_H
