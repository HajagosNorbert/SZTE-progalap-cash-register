//
// Created by Asus on 6/5/2021.
//
//Péter
#include "item.h"
#include <stdio.h>
#include <stdlib.h>

void printItem(item item) {
    printf("%s X %d %d Ft\n", item.name, item.count, item.price);
}

//Norbert

int countItems(itemNode *head) {
    itemNode *current = head;

    int itemCount = 0;
    while (current != NULL) {
        itemCount++;
        current = current->next;
    }

    return itemCount;
}

void addItem(itemNode *head, item *item) {
    itemNode *current = head;

    while (current != NULL) {
        current = current->next;
    }

    current = (itemNode *)malloc(sizeof(itemNode));
    current->item = item;
    current->next = NULL;
}