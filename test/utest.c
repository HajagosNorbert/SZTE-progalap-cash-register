#include "item.h"
#include "utest_item.h"

#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
//Norbert

//1. tesztkészlet neve
//2. fv pointer, amely a készlet összes eleme előtt lefut
//3. mint a 2. ,de a tesztesetek után fut le
//4. mint a 2. csak az egész tesztkészlet előtt fut le
//5. mint a 4. csak az egész készlet után fut le
//6. teszt-eset lista (ami egy tömb)
// egy suit felépül: {1, 2, 3, 4, 5, 6 } -ból
//CU_SUITE_INFO_NULL = a tesztkészletek vége

//itemTests
CU_SuiteInfo suites[] = {
    {"logic", NULL, NULL, NULL, NULL, itemTests},
    // { "manipulation", NULL, NULL, manip_test_setup, manip_test_teardown, manipulation_tests },
    CU_SUITE_INFO_NULL};

int main() {
    if (CU_initialize_registry() != CUE_SUCCESS) {
        return -1;
    };
    if (CU_register_suites(suites) != CUE_SUCCESS) {
        return -1;
    };
    CU_basic_set_mode(CU_BRM_NORMAL);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
