//
// Created by Asus on 6/5/2021.
//
//Péter
#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printItem(item *item) {
    printf("%s X %d %d Ft\n", item->name, item->count, item->price);
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

void addItem(itemNode **head, item item) {
    itemNode *temp, *ptr;
    temp = (itemNode *)malloc(sizeof(itemNode));
    // temp->item = item;
    temp->item.count = item.count;
    temp->item.price = item.price;
    strcpy(temp->item.name, item.name);
    // memcpy(&item.name, &(temp->item.name), sizeof(item.name));
    temp->next = NULL;

    if (*head == NULL) {
        *head = temp;
        return;
    }

    ptr = *head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
}