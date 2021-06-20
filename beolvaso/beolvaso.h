//
// Created by Asus on 6/5/2021.
//

#ifndef BEOLVASO_H
#define BEOLVASO_H

#include "item.h"

void printKeyboard(const char *msg);

int checkInputName(const char row[]);

int checkInputPriceQuan(const char row[]);

void readName(item* i1,int* x, int* ok, int* printer);

void readPrice(item* i1,int* x);

void readQuan(item* i1,int* x, int* ok);

itemNode *beolvaso();

#endif //BEOLVASO_H
