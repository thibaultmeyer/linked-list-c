#ifndef LINKEDLIST_H
# define LINKEDLIST_H

typedef struct s_linkedlist_node s_linkedlist_node;
typedef struct s_linkedlist      s_linkedlist;

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

void linkedlist_add_back(s_linkedlist *linked_list, void *data);

void linkedlist_add_front(s_linkedlist *linked_list, void *data);

s_linkedlist *linkedlist_create(void);

void linkedlist_destroy(s_linkedlist *linked_list, void (*fun_on_each)(void *item));

void *linkedlist_get(s_linkedlist *linked_list, unsigned int index);

void *linkedlist_remove(s_linkedlist *linked_list, unsigned int index);

void linkedlist_remove_if(s_linkedlist *linked_list, int (*fun_check)(void *data), int (*fun_destroy)(void *data));

void linkedlist_remove_if_null(s_linkedlist *linked_list);

unsigned int linkedlist_size(s_linkedlist *linked_list);

#endif //LINKEDLIST_H
