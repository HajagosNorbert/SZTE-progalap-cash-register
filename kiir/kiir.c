#include "item.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>

//Viktor
static  FILE* out;
static int ar=0;
//static int szelesseg=20;
char *substring(char *string, int position, int length)
{
    char *p;
    int c;
    p = malloc(length+1);

    if (p == NULL)
    {
        exit(1);
    }
    for (c = 0; c < length; c++)
    {
        *(p+c) = *(string+position-1);
        string++;
    }
    *(p+c) = '\0';

    return p;
}
void printToFileItem(item *item,int szelesseg, int blockNumber) {
    int nevHossz=strlen(item->name);
    int ArHossz = snprintf( NULL, 0, "%d", item->price );
    int DbHossz = snprintf( NULL, 0, "%d", item->count );
    int ArDbHossz=7+ ArHossz+DbHossz;

    if(nevHossz<(szelesseg-ArDbHossz)){//minden kifer egy sorban
        fprintf(out,"%s", item->name);
        for(int i=0; i<(szelesseg-nevHossz-ArDbHossz);i++){
            fprintf(out,"_");
        }
        fprintf(out,"%d db %dFt<br>",  item->count, item->price);
    } else if(nevHossz>szelesseg){
        char *nameString=item->name;
        char *nameStringSplit= strtok(nameString," ");
        printf("%s", nameStringSplit);
        while (nameStringSplit != NULL)
        {
            if( strlen(nameStringSplit)<szelesseg){
                fprintf(out,"%s", nameStringSplit);
                for(int i=0; i<(szelesseg-strlen(nameStringSplit));i++){
                    fprintf(out,"_");
                }
                fprintf(out,"<br>");
                nameStringSplit = strtok(NULL, " ");
            } else{
                int splitSzam=strlen(nameStringSplit)/szelesseg;
                int i=0;
                int position=0;
                while (i<splitSzam){
                    printf("hello\n");
                    char *split= substring(nameStringSplit,position,szelesseg-1);
                    fprintf(out,"%s",split);
                    fprintf(out,"<br>");
                    position+=szelesseg-1;
                    i++;
                }
                fprintf(out,"HIBAS TETELNEV");
                fprintf(out,"<br>");
                break;
            }
        }
        for(int i=0; i<(szelesseg-ArDbHossz);i++){
            fprintf(out,"_");
        }
        fprintf(out,"%d db %dFt<br>",  item->count, item->price);
    } else {//szo kifer egy sorban de az ar mar nem fel oda
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

void printOutList(itemNode *head,int szelesseg, int int nyugtaHossz, int blockNumber) {
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
        printToFileItem(&(current->item), blockNumber);
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