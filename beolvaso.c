//
// Created by Asus on 6/5/2021.
//

#include "beolvaso.h"
#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char values[9][4] = {{32},
                     {'a', 'b', 'c'},
                     {'d', 'e', 'f'},
                     {'g', 'h', 'i'},
                     {'j', 'k', 'l'},
                     {'m', 'n', 'o'},
                     {'p', 'q', 'r', 's'},
                     {'t', 'u', 'v'},
                     {'w', 'x', 'y', 'z'}};
item items[20];

void printKeyboard(char *msg) {
    printf("%s\n", msg);
    printf("_______________________________________\n"
           "|1(space)  |2(a/b/c) |3(d/e/f)  | Ok |\n"
           "|4(g/h/i)  |5(j/k/l) |6(m/n/o)  | X  |\n"
           "|7(p/q/r/s)|8(t/u/v) |9(w/x/y/z)| Ny |\n");
    printf("\n");
}

int checkInputName(char row[]) {
    int k = 1;
    if (row[0] < '0' || row[0] > '9') {
        return 0;
    }
    while (row[k] != '\0') {
        if (row[0] != row[k]) {
            return 0;
        }
        k++;
    }
    return 1;
}

int checkInputPriceQuan(char row[]) {
    int k = 0;
    while (row[k] != '\0') {
        if (row[k] < '0' || row[k] > '9') {
            return 0;
        }
        k++;
    }
    return 1;
}

item *beolvaso() {

    item i1;
    int numberOfItems = 0;
    int ok;
    int x;
    int printer = 0;

    while (printer == 0) {

        strcpy(i1.name, "");
        i1.count = 0;
        i1.price = 0;
        ok = 1;
        x = 0;

        while (x == 0) {
            char row[5];

            printKeyboard("Kerem a termek nevet...");
            scanf("%s", row);

            while (!(strcmp(row, "x") == 0 || strcmp(row, "ny") == 0 || checkInputName(row) == 1)) {
                if (strcmp(row, "ny") == 0 && strlen(i1.name) == 0) {
                    printf("Can't print. Name is empty.\n");
                } else if (!(strcmp(row, "x") == 0 || strcmp(row, "x") == 0 || checkInputName(row) == 1)) {
                    printf("Wrong input! Type again...\n");
                }
                printKeyboard("Kerem a termek nevet...");
                scanf("%s", row);
            }

            if (strcmp(row, "ny") == 0) {
                printer = 1;
                break;
            } else if (strcmp(row, "x") == 0) {
                x++;
            } else {
                int k = 0;
                while (row[k] != '\0') {
                    k++;
                }
                char c[2] = {values[row[0] - 49][k - 1], '\0'};
                strcat(i1.name, c);
                printf("Termek neve: %s\n", i1.name);
            }
        }
        while (x == 1) {
            char row[6];

            printKeyboard("Kerem a termek arat...");
            scanf("%s", row);

            while (!(strcmp(row, "x") == 0 || checkInputPriceQuan(row))) {
                printf("Wrong input! Type again...");
                printKeyboard("Kerem a termek arat...");
                scanf("%s", row);
            }

            if (strcmp(row, "x") == 0) {
                x++;
            } else {
                i1.price = atoi(row);
            }
        }
        while (ok && x == 2) {
            char row[6];

            printKeyboard("Kerem a darabszamot...");
            scanf("%s", row);

            while (!(strcmp(row, "ok") == 0 || checkInputPriceQuan(row))) {
                printf("Wrong input! Type again...\n");
                printKeyboard("Kerem a darabszamot...\n");
                scanf("%s", row);
            }

            if (strcmp(row, "ok") == 0) {
                ok = 0;
                x = 0;
                printItem(i1);
            } else {
                i1.count = atoi(row);
            }
        }

        if (printer == 0) {
            items[numberOfItems] = i1;
            numberOfItems++;
            x = 0;
            ok = 1;
        }
    }

    return items;
}