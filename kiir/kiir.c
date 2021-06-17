#include "item.h"
#include <stdio.h>
#include <time.h>
#include <string.h>

static  FILE* out;
static int ar=0;
static int szelesseg=20;
void printToFileItem(item *item) {
    int nevHossz=strlen(item->name);
    int ArHossz = snprintf( NULL, 0, "%d", item->price );
    int DbHossz = snprintf( NULL, 0, "%d", item->count );
    int ArDbHossz=7+ ArHossz+DbHossz;

    if(nevHossz<(szelesseg-ArDbHossz)){
        fprintf(out,"%s", item->name);
        for(int i=0; i<(szelesseg-nevHossz-ArDbHossz);i++){
            fprintf(out,"_");
        }
        fprintf(out,"%d db %dFt<br>",  item->count, item->price);

    } else if(nevHossz>szelesseg){
        char *nameString=item->name;
        char *nameStringSplit= strtok(nameString," ");
        while (nameStringSplit != NULL)
        {
            fprintf(out,"%s", nameStringSplit);
            for(int i=0; i<(szelesseg-strlen(nameStringSplit));i++){
                fprintf(out,"_");
            }
            fprintf(out,"<br>");
            nameStringSplit = strtok(NULL, " ");
        }
        for(int i=0; i<(szelesseg-ArDbHossz);i++){
            fprintf(out,"_");
        }
        fprintf(out,"%d db %dFt<br>",  item->count, item->price);
    } else{
        fprintf(out,"%s", item->name);
        for(int i=0; i<(szelesseg-nevHossz);i++){
            fprintf(out,"_");
        }
        fprintf(out,"<br>");
        for(int i=0; i<(szelesseg-ArDbHossz);i++){
            fprintf(out,"_");
        }
        fprintf(out,"%d db %dFt<br>",  item->count, item->price);
    }
    ar+=(item->count)*(item->price);
}

void printOutList(itemNode *head) {
    itemNode *current = head;

    printf("\nLista hossza: %d\n", countItems(head));
    out= fopen("nyugta.html","w");
    fprintf(out,"<!DOCTYPE html><html lang=\"hu\"><head><meta charset=\"UTF-8\"> <meta name=\"author\" content=\"Fajka Viktor, Hajagos Norbert és Zabos Péter\"/>");
    fprintf(out,"<title>Nyugta</title>");
    fprintf(out,"<style>");
    fprintf(out,"#ar{text-align: right;}");
    fprintf(out,"#osszeg{text-align: right;}");

    fprintf(out,"</style>");
    fprintf(out,"</head>");
    fprintf(out,"<body>");
    fprintf(out,"<div id=\"nyugta\">");

    fprintf(out,"<h2>Nyugta</h2>");
    //TODO: hanyadik szamla
    while (current != NULL) {
        printToFileItem(&(current->item));
        current = current->next;
    }
    fprintf(out,"<br>");
    fprintf(out,"Összesen:");
    int arhossza = snprintf( NULL, 0, "%d", ar );
    for(int i=0; i<szelesseg-12-arhossza;i++){
        fprintf(out,"_");
    }
    fprintf(out,"%dFt<br>",ar);
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(out," %d. %02d. %02d.", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    fprintf(out,"</div>");
    fprintf(out,"</body>");
    fprintf(out,"</html>");
    fclose(out);

}