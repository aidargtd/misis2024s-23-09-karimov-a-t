
add_executable(complex_test complex_test.cpp
        doctest.h)
target_link_libraries(complex_test complex)

add_executable(rational_test rational_test.cpp)
target_link_libraries(rational_test rational)

add_executable(dynarr_test dynarr_test.cpp)
target_link_libraries(dynarr_test dynarr)
