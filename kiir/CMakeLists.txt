# Norbi
add_library(kiir kiir.c)
target_link_libraries(kiir item)

target_include_directories(kiir PUBLIC .)
