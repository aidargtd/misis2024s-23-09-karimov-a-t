add_library(StackArrT StackArrT.сpp)
target_include_directories(StackArrT PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)
install(TARGETS StackArrT)
