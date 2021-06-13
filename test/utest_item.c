#include "utest_item.h"
#include "item.h"

#include <CUnit/CUnit.h>
#include <stdlib.h>

static void testCountItems() {
    item mockItem1 = {"alma", 300, 2};
    item mockItem2 = {"fakereg", 45, 4};

    itemNode *mockNode1;
    CU_ASSERT_EQUAL(countItems(mockNode1), 0);

    mockNode1 = malloc(sizeof(itemNode));
    itemNode *mockNode2 = malloc(sizeof(itemNode));
    mockNode1->item = mockItem1;
    CU_ASSERT_EQUAL(countItems(mockNode1), 1);
    mockNode1->next = mockNode2;
    mockNode2->item = mockItem2;
    CU_ASSERT_EQUAL(countItems(mockNode1), 2);
}

// static void test_rgbpic_create() {
//     rgbpic_t *pic = rgbpic_create(6, 8, 255);
//     CU_ASSERT_PTR_NOT_NULL(pic);
//     CU_ASSERT_EQUAL(pic->width, 6);
//     CU_ASSERT_EQUAL(pic->height, 8);
//     CU_ASSERT_EQUAL(pic->maxpixvalue, 255);
//     CU_ASSERT_PTR_NOT_NULL(pic->pixelvalues);
//     rgbpic_delete(pic);
// }

// static void test_rgbpic_rgb_to_gray() {
//     rgbpic_pixel_t black = {.red = 0, .green = 0, .blue = 0};
//     rgbpic_pixel_t red = {.red = 100, .green = 0, .blue = 0};
//     rgbpic_pixel_t green = {.red = 0, .green = 100, .blue = 0};
//     rgbpic_pixel_t blue = {.red = 0, .green = 0, .blue = 100};
//     rgbpic_pixel_t yellow = {.red = 100, .green = 100, .blue = 0};
//     rgbpic_pixel_t cyan = {.red = 0, .green = 100, .blue = 100};
//     rgbpic_pixel_t purple = {.red = 100, .green = 0, .blue = 100};
//     rgbpic_pixel_t white = {.red = 100, .green = 100, .blue = 100};
//     CU_ASSERT_EQUAL(rgbpic_rgb_to_gray(black), 0);
//     CU_ASSERT_EQUAL(rgbpic_rgb_to_gray(red), 30);
//     CU_ASSERT_EQUAL(rgbpic_rgb_to_gray(green), 59);
//     CU_ASSERT_EQUAL(rgbpic_rgb_to_gray(blue), 11);
//     CU_ASSERT_EQUAL(rgbpic_rgb_to_gray(yellow), 89);
//     CU_ASSERT_EQUAL(rgbpic_rgb_to_gray(cyan), 70);
//     CU_ASSERT_EQUAL(rgbpic_rgb_to_gray(purple), 41);
//     CU_ASSERT_EQUAL(rgbpic_rgb_to_gray(white), 100);
// }

// static void test_rgbpic_coord() {
//     rgbpic_t *pic = rgbpic_create(6, 8, 255);
//     int t = 0;
//     for (int y = 0; y < 8; ++y) {
//         for (int x = 0; x < 6; ++x) {
//             CU_ASSERT_EQUAL(rgbpic_coord(pic, x, y), t++);
//         }
//     }
//     rgbpic_delete(pic);
// }

// {név, tesztesetet megalósító függvény}
CU_TestInfo itemTests[] = {
    {"Counting items", testCountItems},
    // {"creation", test_rgbpic_create},
    // {"gray conversion", test_rgbpic_rgb_to_gray},
    // {"coordinate computation", test_rgbpic_coord},

    CU_TEST_INFO_NULL};
