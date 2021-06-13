# Norbi
add_library(item item.c)

target_link_libraries(item INTERFACE debug_tools)
target_include_directories(item PUBLIC .)
