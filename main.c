#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lists_extended.h"

void main(){
    List* list = ListCreate(CHAR);

    ListInsertChar(list, 0, 'a');
    ListInsertChar(list, 0, 'b');
    ListInsertChar(list, 0, 'c');
    ListInsertChar(list, 0, 'd');
    ListPrint(list);
    ListRemove(list, 0);
    ListPrint(list);
    ListDelete(list);
}