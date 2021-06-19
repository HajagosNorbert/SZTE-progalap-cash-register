//
// Péter
//

#include "beolvaso.h"
#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include <CUnit/CUnit.h> //Norbert

#define BUFFER 32

const int maxValues[9] = {1,3,3,3,3,3,4,3,4};

const char values[9][4] = {{32},
                     {'a', 'b', 'c'},
                     {'d', 'e', 'f'},
                     {'g', 'h', 'i'},
                     {'j', 'k', 'l'},
                     {'m', 'n', 'o'},
                     {'p', 'q', 'r', 's'},
                     {'t', 'u', 'v'},
                     {'w', 'x', 'y', 'z'}};

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
        return -1;
    }
    while (row[k] != '\0') {
        if (row[0] != row[k]) {
            return -1;
        }
        k++;
    }
    k=(k-1) % maxValues[row[0]-49]+1;
    return k;
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

char *readString()
{
    char *str = malloc(sizeof(char) * BUFFER), *err;
    int pos;
    for(pos = 0; str != NULL && (str[pos] = getchar()) != '\n'; pos++)
    {
        if(pos % BUFFER == BUFFER - 1)
        {
            if((err = realloc(str, sizeof(char) * (BUFFER + pos + 1))) == NULL)
                free(str);
            str = err;
        }
    }
    if(str != NULL)
        str[pos] = '\0';
    return str;
}

void readName(item* i1,int* x, int* ok, int* printer){
    while(*x==0){
        char *row = NULL;

        printKeyboard("Kerem a termek nevet...");
        row=readString();

        while (!(strcmp(row, "x") == 0 || strcmp(row, "ny") == 0 || checkInputName(row) >= 0)) {
            if (strcmp(row, "ny") == 0 && strlen(i1->name) == 0) {
                printf("Can't print. Name is empty.\n");
            } else if (!(strcmp(row, "x") == 0 || strcmp(row, "x") == 0 || checkInputName(row) >= 0)) {
                printf("Wrong input! Type again...\n");
            }
            printKeyboard("Kerem a termek nevet...");
            row=readString();
        }

        if (strcmp(row, "ny") == 0) {
            *printer = 1;
            break;
        } else if (strcmp(row, "x") == 0) {
            (*x)++;
        } else {
            int k = checkInputName(row);
            char c[2] = {values[row[0] - 49][k - 1], '\0'};
            strcat(i1->name, c);
            printf("Termek neve: %s\n", i1->name);
        }
        free(row);
    }

}

void readPrice(item* i1,int* x, int* ok, int* printer){

    while(*x==1){

        char *row = NULL;

        printKeyboard("Kerem a termek arat...");
        row=readString();

        while (!(strcmp(row, "x") == 0 || checkInputPriceQuan(row))) {
            printf("Wrong input! Type again...");
            printKeyboard("Kerem a termek arat...");
            row=readString();
        }

        if (strcmp(row, "x") == 0) {
            (*x)++;
        } else {
            i1->price = atoi(row);
        }
        free(row);
    }
}

void readQuan(item* i1,int* x, int* ok, int* printer){

    while (*ok==1 && *x == 2) {

        char *row = NULL;

        printKeyboard("Kerem a darabszamot...");
        row=readString();

        while (!(strcmp(row, "ok") == 0 || checkInputPriceQuan(row))) {
            printf("Wrong input! Type again...\n");
            printKeyboard("Kerem a darabszamot...\n");
            row=readString();
        }

        if (strcmp(row, "ok") == 0) {
            *ok = 0;
            *x = 0;
            printItem(i1);
        } else {
            i1->count = atoi(row);
        }
        free(row);
    }

}

itemNode *beolvaso() {
    //Norbert
    itemNode *head = NULL;
    //Péter
    item i1;
    int ok;
    int x;
    int printer = 0;

    while (printer == 0) {

        strcpy(i1.name, "");
        i1.count = 0;
        i1.price = 0;
        ok = 1;
        x = 0;

        readName(&i1,&x,&ok,&printer);
        readPrice(&i1,&x,&ok,&printer);
        readQuan(&i1,&x,&ok,&printer);

        if (printer == 0) {
            //Norbert
            addItem(&head, i1);
            //Péter
            x = 0;
            ok = 1;
        }
    }
    //Norbert
    return head;
    //Péter
}