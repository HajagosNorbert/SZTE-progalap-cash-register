#include <stdio.h>
#include <stdlib.h>

#include "beolvaso.h"
#include "item.h"
#include "kiir.h"

int main(int argc, char *argv[]) {
    //Norbert
    char *nyugtaHossz;
    if (argc == 2) {
        nyugtaHossz = argv[1];
    } else {
        fprintf(stdout, "Adjon meg egy argumentumot, ami a nyugta hosszat jelzi! ");
        nyugtaHossz = "20";
    }

    itemNode *firstItem;
    firstItem = beolvaso();
    printOutList(firstItem, nyugtaHossz);
    freeItems(firstItem);
    return 0;
}
