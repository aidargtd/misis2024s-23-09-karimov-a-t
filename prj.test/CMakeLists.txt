
add_executable(complex_test complex_test.cpp
        doctest.h)
target_link_libraries(complex_test complex)

add_executable(rational_test rational_test.cpp)
target_link_libraries(rational_test rational)

add_executable(dynarr_test dynarr_test.cpp)
target_link_libraries(dynarr_test dynarr)

add_executable(StackArrT_test StackArrT_test.cpp)
target_link_libraries(StackArrT_test StackArrT)


add_executable(DoubleListQueue_test DoubleListQueue_test.cpp)
target_link_libraries(DoubleListQueue_test DoubleListQueue)


add_executable(StackLstT_test StackLstT_test.cpp)
target_link_libraries(StackLstT_test StackLstT)

add_executable(BinarySearchTree_test BinarySearchTree_test.cpp)
target_link_libraries(BinarySearchTree_test BinarySearchTree)

add_executable(HashTable_test HashTable_test.cpp)
target_link_libraries(HashTable_test HashTable)

add_executable(CustomContainer_test CustomContainer_test.cpp)
target_link_libraries(CustomContainer_test CustomContainer)