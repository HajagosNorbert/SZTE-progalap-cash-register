//
// Created by Asus on 6/5/2021.
//

#ifndef UNTITLED1_ITEM_H
#define UNTITLED1_ITEM_H

#include <stdio.h>

typedef struct itemType {
    char name[20];
    int price;
    int count;
} itemType;

void printItem(itemType item);

#endif //UNTITLED1_ITEM_H
