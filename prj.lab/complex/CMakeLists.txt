add_library(complex complex.cpp complex.hpp
        ../../prj.test/complex_test.cpp)
#add_executable(complex_test ../prj_test/complex_test.cpp)
set_property(TARGET complex PROPERTY CXX_STANDARD 11)
target_include_directories(complex PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)
install(TARGETS complex)