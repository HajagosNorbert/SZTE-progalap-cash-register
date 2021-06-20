#include <stdio.h>
#include <stdlib.h>

#include "beolvaso.h"
#include "item.h"
#include "kiir.h"

int main(int argc, char *argv[]) {
    //Norbert
    int nyugtaHossz;
    if (argc == 2) {
        nyugtaHossz = atoi(argv[1]);
    } else {
        fprintf(stdout, "Adjon meg egy argumentumot, ami a nyugta hosszat jelzi!\n");
        nyugtaHossz = 20;
    }

    int blockNumber=1;
    itemNode *firstItem;
    firstItem = beolvaso();
    printOutList(firstItem, nyugtaHossz, blockNumber);
    freeItems(firstItem);
    return 0;
}
