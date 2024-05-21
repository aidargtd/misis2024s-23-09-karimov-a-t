add_library(CustomContainer CustomContainer.cpp CustomContainer.hpp
        ../../prj.test/CustomContainer_test.cpp
)

set_property(TARGET CustomContainer PROPERTY CXX_STANDARD 11)
target_include_directories(CustomContainer PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)
install(TARGETS CustomContainer)