add_library(StackArrT StackArrT.cpp StackArrT.hpp
        ../../prj.test/StackArrT_test.cpp
)

set_property(TARGET StackArrT PROPERTY CXX_STANDARD 11)
target_include_directories(StackArrT PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)
install(TARGETS StackArrT)