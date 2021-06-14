#include <stdio.h>
#include <stdlib.h>

#include "beolvaso.h"
#include "item.h"
#include "kiir.h"

int main() {
    //Norbert
    itemNode *firstItem;
    firstItem = beolvaso();
    printOutList(firstItem);
    freeItems(firstItem);
    return 0;
}
