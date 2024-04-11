add_library(StackLstT StackLstT.cpp StackLstT.hpp)
target_include_directories(StackLstT PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)
install(TARGETS StackLstT)
