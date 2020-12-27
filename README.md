# Linked List (C Programming)

[![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/thibaultmeyer/linked-list-c/blob/master/LICENSE)
[![CodeFactor](https://www.codefactor.io/repository/github/thibaultmeyer/linked-list-c/badge)](https://www.codefactor.io/repository/github/thibaultmeyer/linked-list-c)

A linked list implementation in C.
*****


## Build & install the library
To compile this library, you must ensure that a C compiler and CMake are correctly installed.

    #> mkdir cmake-build-release
    #> cd cmake-build-debug
    #> cmake -DCMAKE_BUILD_TYPE=Release ..
    #> make
    #> make install



## Available functions

| Function                     | Complexity  | Description                                                             |
| ---------------------------- | ----------- | ----------------------------------------------------------------------- |
| linkedlist_add               | O(n)        | Adds an element to the linked list                                      |
| linkedlist_add_front         | O(1)        | Adds an element at the end of the linked list                           |
| linkedlist_add_back          | O(1)        | Adds an element at the beginning of the linked list                     |
| linkedlist_apply             | O(n)        | Applies a function to all the elements of the linked list               |
| linkedlist_create            | O(1)        | Creates a new linked list                                               |
| linkedlist_destroy           | O(n)        | Destroys an existing linked list                                        |
| linkedlist_dump_console      | O(n)        | Dump a linked list in standard output (STDOUT)                          |
| linkedlist_dump_dotgraph     | O(n)        | Dump a linked list into a "DOT graph" file                              |
| linkedlist_find              | O(n)        | Find one or more elements in the linked list                            |
| linkedlist_find_first        | O(n)        | Find the first matching element in the linked list                      |
| linkedlist_find_last         | O(n)        | Find the last matching element in the linked list                       |
| linkedlist_get               | O(n)        | Retrieves a specific element from the linked list                       |
| linkedlist_get_back          | O(1)        | Retrieves the last element of the linked list                           |
| linkedlist_get_front         | O(1)        | Retrieves the first element of the linked list                          |
| linkedlist_is_empty          | O(1)        | Check if the linked list is empty                                       |
| linkedlist_iterator_create   | O(1)        | Creates an iterator for the given linked list                           |
| linkedlist_iterator_destroy  | O(1)        | Destroys an existing iterator                                           |
| linkedlist_iterator_has_next | O(1)        | Check if the iteration has more elements                                |
| linkedlist_iterator_next     | O(1)        | Retrieves the next element                                              |
| linkedlist_merge             | O(n)        | Merges two linked lists. The "target" linked list is the first argument |
| linkedlist_remove            | O(n)        | Removes the element at the specified position in the linked list        |
| linkedlist_remove_if         | O(n)        | Removes all matching elements from a linked list                        |
| linkedlist_remove_if_null    | O(n)        | Removes all NULL elements from a linked list                            |
| linkedlist_reverse           | O(n)        | Reverse the elements of the linked list                                 |
| linkedlist_size              | O(1)        | Retrieves the number of elements in the linked list                     |
| linkedlist_sort              | O(n*n)      | Sort a linked list                                                      |



## License
This project is released under terms of the [MIT license](https://github.com/thibaultmeyer/linked-list-c/blob/master/LICENSE).
