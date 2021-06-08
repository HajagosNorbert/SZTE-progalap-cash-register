#include <stdio.h>

#include "beolvaso.h"
#include "item.h"

int main() {
    item *cuccok;
    cuccok = beolvaso();
    for (int i = 0; i < 2; i++) {
        printItem(cuccok[i]);
    }
    return 0;
}
