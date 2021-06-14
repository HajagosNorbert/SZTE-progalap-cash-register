//
// Created by Asus on 6/5/2021.
//

#ifndef BEOLVASO_H
#define BEOLVASO_H

#include "item.h"

void printKeyboard(char *msg);

int checkInputName(char row[]);

int checkInputPriceQuan(char row[]);

void readName(item* i1,int* x, int* ok, int* printer);

void readPrice(item* i1,int* x, int* ok, int* printer);

void readQuan(item* i1,int* x, int* ok, int* printer);

itemNode *beolvaso();

#endif //BEOLVASO_H
