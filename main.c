#include <stdio.h>

#include "item.h"
#include "beolvaso.h"

int main() {
    itemType *cuccok;
    cuccok = beolvaso();
    for (int i = 0; i < 2; i++) {
        printItem(cuccok[i]);
    }
    return 0;
}
