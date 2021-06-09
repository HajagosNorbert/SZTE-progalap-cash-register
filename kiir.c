#include "item.h";
#include <stdio.h>

void printOutList(itemNode *head) {

    itemNode *current = head;
    while (current != NULL) {
        printItem(&(current->item));
        current = current->next;
    }
    printf("\nLista hossza: %d", countItems(head));
}