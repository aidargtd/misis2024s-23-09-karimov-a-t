add_library(dynarr dynarr.cpp dynarr.hpp)
target_include_directories(dynarr PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)
install(TARGETS dynarr)
