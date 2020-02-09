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

| Function                     | Complexity  | Description                                 |
| ---------------------------- | ----------- | ------------------------------------------- |
| linkedlist_add               | O(n)        | Adds item anywhere in the list              |
| linkedlist_add_front         | O(1)        | Adds item at the beginning of the list      |
| linkedlist_add_back          | O(1)        | Adds item at the end of the list            |
| linkedlist_apply             | O(n)        | Applies processing to all items in the list |
| linkedlist_create            | O(1)        | Creates a new list                          |
| linkedlist_destroy           | O(n)        | Destroys an existing list                   |
| linkedlist_dump_console      | O(n)        | Shows all items in the list                 |
| linkedlist_dump_dotgraph     | O(n)        | Shows all items in the list (DOT graph)     |
| linkedlist_find_first        | O(n)        | Finds the first matching item in the list   |
| linkedlist_find_last         | O(n)        | Finds the last matching item in the list    |
| linkedlist_get               | O(n)        | Retrieves an item from the list             |
| linkedlist_get_back          | O(1)        | Retrieves the last item in the list         |
| linkedlist_get_front         | O(1)        | Retrieves the first item in the list        |
| linkedlist_iterator_create   | O(1)        | Creates an iterator for the given list      |
| linkedlist_iterator_destroy  | O(1)        | Destroys an existing iterator               |
| linkedlist_iterator_has_next | O(1)        | Checks if iterator has a next item          |
| linkedlist_iterator_next     | O(1)        | Retrieves the next item                     |
| linkedlist_remove            | O(n)        | Removes an item from the list               |
| linkedlist_remove_if         | O(n)        | Removes the matching items from the list    |
| linkedlist_remove_if_null    | O(n)        | Removes all null items from the list        |
| linkedlist_reverse           | O(n)        | Reverses the list                           |
| linkedlist_size              | O(1)        | Retrieves the list size                     |
| linkedlist_sort              | O(n*n)      | Sorts the list                              |



## License
This project is released under terms of the [MIT license](https://github.com/thibaultmeyer/linked-list-c/blob/master/LICENSE).
