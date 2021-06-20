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
#define WIM printf("Rossz input! Irjon ujra...\n") //wrong input message
#define TBNM printf("Tul nagy szam...\n") //too big number message

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

void printKeyboard(const char *msg) {
    printf("%s\n", msg);
    printf("_______________________________________\n"
           "|1(space)  |2(a/b/c) |3(d/e/f)  | Ok |\n"
           "|4(g/h/i)  |5(j/k/l) |6(m/n/o)  | X  |\n"
           "|7(p/q/r/s)|8(t/u/v) |9(w/x/y/z)| Ny |\n");
}

int checkInputName(const char row[]) {
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

int checkInputPriceQuan(const char row[]) {
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
        printf("\n");

        while (!(strcmp(row, "X") == 0 || strcmp(row, "Ny") == 0 || checkInputName(row) >= 0 || (strcmp(row,"Exit")==0))) {
            WIM;
            printf("Termek neve: %s\n", i1->name);
            printKeyboard("Kerem a termek nevet...");
            row=readString();
            printf("\n");
        }

        if (strcmp(row, "Ny") == 0) {
            if(strlen(i1->name)==0){
                *printer = 1;
                break;
            }else{
                printf("Nem lehet nyomtatni! A termek neve nem ures...\n");
                printf("Termek neve: %s\n", i1->name);
            }
        } else if (strcmp(row, "X") == 0) {
            if(strlen(i1->name)!=0){
                (*x)++;
            }else{
                printf("A termek neve ures!\n");
            }
        }else if(strcmp(row,"Exit")==0){
            free(row);
            exit(0);
        }else {
            if(strlen(i1->name)<ITEM_NAME_LENGTH) {
                int k = checkInputName(row);
                char c[2] = {values[row[0] - 49][k - 1], '\0'};
                strcat(i1->name, c);
                printf("Termek neve: %s\n", i1->name);
            }else{
                printf("Elerte a nev maximalis meretet... Nyomjon X-et!\n");
                printf("Termek neve: %s\n", i1->name);
            }
        }

        free(row);
    }

}

void readPrice(item* i1,int* x){

    while(*x==1){

        char *row = NULL;

        printKeyboard("Kerem a termek arat...");
        row=readString();
        printf("\n");

        while (!(strcmp(row, "X") == 0 || checkInputPriceQuan(row))) {
            WIM;
            printKeyboard("Kerem a termek arat...");
            row=readString();
            printf("\n");
        }

        if (strcmp(row, "X") == 0) {
            if(i1->price!=0){
                (*x)++;
            }else{
                printf("Termek ara nem lehet 0!\n");
            }
        } else {
            if(strlen(row)<9){
                i1->price = atoi(row);
                printf("A termek ara: %dFt\n",i1->price);
            }else {
                TBNM;
                printf("A termek ara: %dFt\n",i1->price);
            }
        }
        free(row);
    }
}

void readQuan(item* i1,int* x, int* ok){

    while (*ok==1 && *x == 2) {

        char *row = NULL;

        printKeyboard("Kerem a darabszamot...");
        row=readString();
        printf("\n");

        while (!(strcmp(row, "Ok") == 0 || checkInputPriceQuan(row))) {
            WIM;
            printKeyboard("Kerem a darabszamot...");
            row=readString();
            printf("\n");
        }

        if (strcmp(row, "Ok") == 0) {
            if(i1->count!=0){
                *ok = 0;
                *x = 0;
                printItem(i1);
            }else{
                printf("Nem vehet 0 darabot!\n");
            }
        } else {
            if(strlen(row)<=9){
                i1->count = atoi(row);
                printItem(i1);
            }else {
                TBNM;
                printItem(i1);
            }
        }
        free(row);
    }

}

itemNode *beolvaso() {
    //Norbert
    itemNode *head = NULL;
    //Péter
    item i1;
    int ok; //boolean
    int x; //0->2
    int printer = 0; //boolean

    while (printer == 0) {

        strcpy(i1.name, "");
        i1.count = 0;
        i1.price = 0;
        ok = 1;
        x = 0;

        readName(&i1,&x,&ok,&printer);
        readPrice(&i1,&x);
        readQuan(&i1,&x,&ok);

        if (printer == 0) {
            //Norbert
            addItem(&head, i1);
            //Péter
            x = 0;
            ok = 1;
        }else{
            if(head==NULL){
                printf("Nem lehet nyomtatni! 0 hosszu a lista...\n") ;
                printer=0;
            }
        }
    }
    //Norbert
    return head;
    //Péter
}