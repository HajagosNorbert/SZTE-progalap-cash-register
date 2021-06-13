//
// Created by Asus on 6/5/2021.
//

//Péter
#ifndef ITEM_H
#define ITEM_H
//Norbert
#define ITEM_NAME_LENGTH 20
//Péter
typedef struct item {
    char name[ITEM_NAME_LENGTH];
    int price;
    int count;
} item;

//Norbert
typedef struct itemNode {
    item item;
    struct itemNode *next;
} itemNode;

//Péter
void printItem(item *item);

//Norbert
int countItems(itemNode *head);
void addItem(itemNode **head, item item);

#endif //ITEM_H
