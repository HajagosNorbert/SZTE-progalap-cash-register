#include "item.h"
#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

//Viktor
static FILE *out;
static int ar = 0;
char *substring(char *string, int position, int length) {
    char *p;
    int c;
    p = malloc(length + 1);

    if (p == NULL) {
        return 0;
    }
    for (c = 0; c < length; c++) {
        *(p + c) = *(string + position - 1);
        string++;
    }
    *(p + c) = '\0';
    return p;
}
void printToFileItem(item *item, int szelesseg, int blockNumber) {
    int nevHossz = strlen(item->name);
    int ArHossz = snprintf(NULL, 0, "%d", item->price);
    int DbHossz = snprintf(NULL, 0, "%d", item->count);
    int ArDbHossz = 7 + ArHossz + DbHossz;

    if (nevHossz < (szelesseg - ArDbHossz)) {
        fprintf(out, "%s", item->name);
        for (int i = 0; i < (szelesseg - nevHossz - ArDbHossz); i++) {
            fprintf(out, "_");
        }
        fprintf(out, "%d db %dFt<br>", item->count, item->price);
    } else if (nevHossz > szelesseg) {
        char *nameString = item->name;
        char *nameStringSplit = strtok(nameString, " ");
        printf("%s", nameStringSplit);
        while (nameStringSplit != NULL) {
            if (strlen(nameStringSplit) < szelesseg) {
                fprintf(out, "%s", nameStringSplit);
                for (int i = 0; i < (szelesseg - strlen(nameStringSplit)); i++) {
                    fprintf(out, "_");
                }
                fprintf(out, "<br>");
                nameStringSplit = strtok(NULL, " ");
            } else {
                int position = 0;
                while (position < strlen(nameStringSplit)) {
                    char *split = substring(nameStringSplit, position, szelesseg - 3);
                    fprintf(out, "%s", split);
                    fprintf(out, "<br>");
                    position = position + szelesseg - 3;
                }
                nameStringSplit = strtok(NULL, " ");
            }
        }
        for (int i = 0; i < (szelesseg - ArDbHossz); i++) {
            fprintf(out, "_");
        }
        fprintf(out, "%d db %dFt<br>", item->count, item->price);
    } else {
        fprintf(out, "%s", item->name);
        for (int i = 0; i < (szelesseg - nevHossz); i++) {
            fprintf(out, "_");
        }
        fprintf(out, "<br>");
        for (int i = 0; i < (szelesseg - ArDbHossz); i++) {
            fprintf(out, "_");
        }
        fprintf(out, "%d db %dFt<br>", item->count, item->price);
    }
    ar += (item->count) * (item->price);
}

void printOutList(itemNode *head, int szelesseg, int blockNumber) {
    itemNode *current = head;
    char filename[sizeof "Nyugta100.html"];
    sprintf(filename, "Nyugta%03d.html", blockNumber);
    out = fopen(filename, "w");
    fprintf(out, "<!DOCTYPE html><html lang=\"hu\"><head><meta charset=\"UTF-8\"> <meta name=\"author\" content=\"Fajka Viktor, Hajagos Norbert ??s Zabos P??ter\"/>");
    fprintf(out, "<title>Nyugta</title>");
    fprintf(out, "<style>");
    fprintf(out, "#ar{text-align: right;}");
    fprintf(out, "#osszeg{text-align: right;}");
    fprintf(out, "</style>");
    fprintf(out, "</head>");
    fprintf(out, "<body>");
    fprintf(out, "<div id=\"nyugta\">");

    fprintf(out, "<h2>Nyugta %d</h2>", blockNumber);
    while (current != NULL) {
        printToFileItem(&(current->item), szelesseg, blockNumber);
        current = current->next;
    }
    fprintf(out, "<br>");
    fprintf(out, "??sszesen:");
    int arhossza = snprintf(NULL, 0, "%d", ar);
    for (int i = 0; i < szelesseg - 12 - arhossza; i++) {
        fprintf(out, "_");
    }
    fprintf(out, "%dFt<br>", ar);
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(out, " %d. %02d. %02d.", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    fprintf(out, "</div>");
    fprintf(out, "</body>");
    fprintf(out, "</html>");
    fclose(out);
}