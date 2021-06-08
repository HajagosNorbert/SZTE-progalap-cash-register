#include <stdio.h>

#include "beolvaso.h"
#include "item.h"

int main() {
    //Norbert
    itemNode *firstItem;
    firstItem = beolvaso();

    itemNode *current = firstItem;
    while (current != NULL) {
        printItem(current->item);
        current = current->next;
    }
    printf("%d", countItems(firstItem));
    return 0;
}
