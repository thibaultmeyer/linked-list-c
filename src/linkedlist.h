#ifndef LINKEDLIST_H
# define LINKEDLIST_H
# define LINKEDLIST_RETVAL_SUCCESS 0
# define LINKEDLIST_RETVAL_FAILURE (-1)

typedef enum e_matcher_result        e_matcher_result;
typedef struct s_linkedlist_iterator s_linkedlist_iterator;
typedef struct s_linkedlist_node     s_linkedlist_node;
typedef struct s_linkedlist          s_linkedlist;

typedef void             (*f_applier)(void *element, void *usr_arg);

typedef int              (*f_comparator)(void *element_left, void *element_right);

typedef int              (*f_destroy_element)(void *element);

typedef e_matcher_result (*f_matcher)(void *element, void *usr_arg);

struct s_linkedlist_iterator {
    s_linkedlist_node *current_node;
};

struct s_linkedlist_node {
    s_linkedlist_node *previous;
    s_linkedlist_node *next;
    void              *element;
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

/**
 * Adds an element to the linked list.
 *
 * @param linked_list the linked list in which to add the element
 * @param index index at which the specified element is to be added
 * @param element the element to add
 * @return 0 in case of success, otherwise -1
 */
int linkedlist_add(s_linkedlist *linked_list, unsigned int index, void *element);

/**
 * Adds an element at the end of the linked list.
 *
 * @param linked_list the linked list in which to add the element
 * @param element the element to add
 * @return 0 in case of success, otherwise -1
 */
int linkedlist_add_back(s_linkedlist *linked_list, void *element);

/**
 * Adds an element at the beginning of the linked list.
 *
 * @param linked_list the linked list in which to add the element
 * @param element the element to add
 * @return 0 in case of success, otherwise -1
 */
int linkedlist_add_front(s_linkedlist *linked_list, void *element);

/**
 * Applies a function to all the elements of the linked list.
 *
 * @param linked_list the linked list to use
 * @param applier the function to apply on each element
 * @param applier_arg argument to pass to the function
 */
void linkedlist_apply(s_linkedlist *linked_list, f_applier applier, void *applier_arg);

/**
 * Creates a new linked list. This function will return
 * NULL if a memory allocation error occurs.
 *
 * @return the linked list created, or NULL
 */
s_linkedlist *linkedlist_create(void);

/**
 * Destroys an existing linked list. The second parameter is optional and could be NULL.
 *
 * @param linked_list the linked list to destroy
 * @param fun_on_each the function to be applied to each element before destroying them
 */
void linkedlist_destroy(s_linkedlist *linked_list, void (*fun_on_each)(void *element));

/**
 * Dump a linked list in standard output (STDOUT).
 *
 * @param linked_list the linked list to dump
 * @param fun_render_node_element function to use to render each element
 */
void linkedlist_dump_console(s_linkedlist *linked_list, char *(*fun_render_node_element)(void *element));

/**
 * Dump a linked list into a "DOT graph" file.
 *
 * @param linked_list the linked list to dump
 * @param fun_render_node_element function to use to render each element
 */
void linkedlist_dump_dotgraph(s_linkedlist *linked_list, char *(*fun_render_node_element)(void *element), int file_desc);

/**
 * Find one or more elements in the linked list.
 *
 * @param linked_list the linked list in which to perform the search
 * @param matcher the matcher function
 * @param matcher_arg the matcher function argument
 * @return a new linked list with matched elements
 */
s_linkedlist *linkedlist_find(s_linkedlist *linked_list, f_matcher matcher, void *matcher_arg);

/**
 * Find the first matching element in the linked list.
 *
 * @param linked_list the linked list in which to perform the search
 * @param matcher the matcher function
 * @param matcher_arg the matcher function argument
 * @return the matched element, otherwise NULL
 */
void *linkedlist_find_first(s_linkedlist *linked_list, f_matcher matcher, void *matcher_arg);

/**
 * Find the last matching element in the linked list.
 *
 * @param linked_list the linked list in which to perform the search
 * @param matcher the matcher function
 * @param matcher_arg the matcher function argument
 * @return the matched element, otherwise NULL
 */
void *linkedlist_find_last(s_linkedlist *linked_list, f_matcher matcher, void *matcher_arg);

/**
 * Retrieves a specific element from a linked list.
 *
 * @param linked_list the linked list
 * @param index index of the element to return
 * @return the element at the specified position, otherwise NULL
 */
void *linkedlist_get(s_linkedlist *linked_list, unsigned int index);

/**
 * Retrieves the last element of the linked list.
 *
 * @param linked_list the linked list
 * @return the last element of the linked list, otherwise NULL
 */
void *linkedlist_get_back(s_linkedlist *linked_list);

/**
 * Retrieves the first element of the linked list.
 *
 * @param linked_list the linked list
 * @return the first element of the linked list, otherwise NULL
 */
void *linkedlist_get_front(s_linkedlist *linked_list);

/**
 * Merges two linked lists. The "target" linked list is the first argument.
 *
 * @param linked_list_to the first linked list
 * @param linked_list_from the second linked list
 * @return
 */
int linkedlist_merge(s_linkedlist *linked_list_to, s_linkedlist *linked_list_from);

/**
 * Creates an iterator for the given linked list. This function will return
 * NULL if a memory allocation error occurs.
 *
 * @param linked_list the linked list
 * @return the linked list iterator, otherwise NULL
 */
s_linkedlist_iterator *linkedlist_iterator_create(s_linkedlist *linked_list);

/**
 * Destroys an existing iterator.
 *
 * @param linked_list_iterator the iterator to destroy
 */
void linkedlist_iterator_destroy(s_linkedlist_iterator *linked_list_iterator);

/**
 * Check if the iteration has more elements.
 *
 * @param linked_list_iterator the linked list iterator to test
 * @return returns true if the iteration has more elements.
 */
int linkedlist_iterator_has_next(s_linkedlist_iterator *linked_list_iterator);

/**
 * Retrieves the next element. This function will return NULL
 * if there are no more elements.
 *
 * @param linked_list_iterator the linked list iterator to use
 * @return the next element, otherwise NULL
 */
void *linkedlist_iterator_next(s_linkedlist_iterator *linked_list_iterator);

/**
 * Removes the element at the specified position in the linked list.
 * This function will return NULL if the position does not exist.
 *
 * @param linked_list the linked list
 * @param index the index of the element to be removed
 * @return the element previously at the specified position
 */
void *linkedlist_remove(s_linkedlist *linked_list, unsigned int index);

/**
 * Removes all matching elements from a linked list.
 *
 * @param linked_list the linked list
 * @param matcher the matcher function
 * @param matcher_arg the matcher function argument
 * @param destroy_element the function applied before the element removed
 */
void linkedlist_remove_if(s_linkedlist *linked_list, f_matcher matcher, void *matcher_arg, f_destroy_element destroy_elmt);

/**
 * Removes all NULL elements from a linked list.
 *
 * @param linked_list the linked list
 */
void linkedlist_remove_if_null(s_linkedlist *linked_list);

/**
 * Reverse the elements of the linked list.
 *
 * @param linked_list the linked list to reverse
 */
void linkedlist_reverse(s_linkedlist *linked_list);

/**
 * Retrieves the number of elements in the linked list.
 *
 * @param linked_list the linked list
 * @return the number of elements in the linked list.
 */
unsigned int linkedlist_size(s_linkedlist *linked_list);

/**
 * Sort a linked list.
 *
 * @param linked_list the linked list to sort
 * @param comparator the comparator function to use
 */
void linkedlist_sort(s_linkedlist *linked_list, f_comparator comparator);

#endif //LINKEDLIST_H
