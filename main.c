#include <stdio.h>
#include <stdlib.h>

#include "beolvaso.h"
#include "item.h"
#include "kiir.h"

int main( int argc, char *argv[] ) {
    //Norbert
    itemNode *firstItem;
    firstItem = beolvaso();
    if(argc==2){
        printOutList(firstItem,argv[1]);
    }else{
        printOutList(firstItem,"1");
    }
    freeItems(firstItem);
    return 0;
}
