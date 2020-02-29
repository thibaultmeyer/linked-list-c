CMAKE_MINIMUM_REQUIRED(VERSION 3.10.2)
PROJECT(linked-list-c C)

# Settings
SET(CMAKE_C_STANDARD 99)
SET(CMAKE_C_FLAGS "-Wall")
SET(CMAKE_CXX_FLAGS_DEBUG "-g")
SET(CMAKE_CXX_FLAGS_RELEASE "-O2")

# Source Files
SET(SOURCE_FILES ${SOURCE_FILES}
        src/linkedlist_add.c
        src/linkedlist_add_back.c
        src/linkedlist_add_front.c
        src/linkedlist_apply.c
        src/linkedlist_create.c
        src/linkedlist_destroy.c
        src/linkedlist_dump_console.c
        src/linkedlist_dump_dotgraph.c
        src/linkedlist_find.c
        src/linkedlist_find_first.c
        src/linkedlist_find_last.c
        src/linkedlist_get.c
        src/linkedlist_get_back.c
        src/linkedlist_get_front.c
        src/linkedlist_iterator_create.c
        src/linkedlist_iterator_destroy.c
        src/linkedlist_iterator_has_next.c
        src/linkedlist_iterator_next.c
        src/linkedlist_merge.c
        src/linkedlist_remove.c
        src/linkedlist_remove_if.c
        src/linkedlist_remove_if_null.c
        src/linkedlist_reverse.c
        src/linkedlist_size.c
        src/linkedlist_sort.c)

# Test Files
SET(TEST_FILES ${TEST_FILES}
        test/strcmp_with_s2_nullcheck.c
        test/test_linkedlist_add.c
        test/test_linkedlist_apply.c
        test/test_linkedlist_create_and_destroy.c
        test/test_linkedlist_find.c
        test/test_linkedlist_find_first.c
        test/test_linkedlist_find_last.c
        test/test_linkedlist_get.c
        test/test_linkedlist_iterator_next.c
        test/test_linkedlist_merge.c
        test/test_linkedlist_remove.c
        test/test_linkedlist_remove_if_null.c
        test/test_linkedlist_reverse.c
        test/test_linkedlist_size.c
        test/test_linkedlist_sort.c
        test/main.c)

# Library
ADD_LIBRARY(linked-list-c-obj OBJECT ${SOURCE_FILES})
ADD_LIBRARY(linked-list-c-static STATIC $<TARGET_OBJECTS:linked-list-c-obj>)
ADD_LIBRARY(linked-list-c-shared SHARED $<TARGET_OBJECTS:linked-list-c-obj>)

# Binary (Unit Tests)
ADD_EXECUTABLE(linked-list-c-test $<TARGET_OBJECTS:linked-list-c-obj> ${TEST_FILES})

# Install
INSTALL(TARGETS linked-list-c-static ARCHIVE DESTINATION lib LIBRARY DESTINATION lib RUNTIME DESTINATION bin)
INSTALL(TARGETS linked-list-c-shared ARCHIVE DESTINATION lib LIBRARY DESTINATION lib RUNTIME DESTINATION bin)
INSTALL(DIRECTORY ${CMAKE_SOURCE_DIR}/src/ DESTINATION include FILES_MATCHING PATTERN "*.h*")
