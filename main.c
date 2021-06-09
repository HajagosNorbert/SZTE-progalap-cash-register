#include <stdio.h>

#include "beolvaso.h"
#include "item.h"
#include "kiir.h"

int main() {
    //Norbert
    itemNode firstItem;
    firstItem = beolvaso();
    printOutList(&firstItem);
    return 0;
}
