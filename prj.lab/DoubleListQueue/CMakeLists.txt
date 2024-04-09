add_library(DoubleListQueue DoubleListQueue.hpp
        ../../prj.test/DoubleListQueue_test.cpp
        DoubleListQueue.cpp
)
target_include_directories(DoubleListQueue PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)
install(TARGETS DoubleListQueue)