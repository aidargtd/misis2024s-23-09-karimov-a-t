add_library(complex complex.cpp complex.hpp)
#add_executable(complex_test ../prj_test/complex_test.cpp)
target_include_directories(complex PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)
install(TARGETS complex)
