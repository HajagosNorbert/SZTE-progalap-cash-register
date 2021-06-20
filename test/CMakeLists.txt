# Norbert
enable_testing()

add_executable(utest utest.c utest_item.c)
target_link_libraries(utest item cunit)
add_test(utest ${EXECUTABLE_OUTPUT_PATH}/test)