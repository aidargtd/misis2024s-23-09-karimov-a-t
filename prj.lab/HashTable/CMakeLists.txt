add_library(HashTable HashTable.cpp HashTable.hpp )
set_property(TARGET HashTable PROPERTY CXX_STANDARD 20)
target_include_directories(HashTable PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)
install(TARGETS HashTable)