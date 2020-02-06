CMAKE_MINIMUM_REQUIRED(VERSION 3.10.2)
PROJECT(linked-list-c C)

# Settings
SET(CMAKE_C_STANDARD 99)
SET(CMAKE_C_FLAGS "-Wall")

# Source Files
SET(SOURCE_FILES ${SOURCE_FILES}
        src/linkedlist_add_back.c
        src/linkedlist_add_front.c
        src/linkedlist_create.c
        src/linkedlist_destroy.c
        src/linkedlist_size.c)

# Test Files
SET(TEST_FILES ${TEST_FILES}
        test/test_linkedlist_create_and_destroy.c
        test/test_linkedlist_size.c
        test/main.c)

# Library
ADD_LIBRARY(linked-list-c ${SOURCE_FILES})

# Binary (Unit Tests)
ADD_EXECUTABLE(linked-list-c-test ${SOURCE_FILES} ${TEST_FILES})
