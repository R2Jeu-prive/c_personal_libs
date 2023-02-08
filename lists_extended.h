#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "lists_base.h"

extern int ListCount(List* list){
    assert(list != NULL);

    int n = 0;
    ListNode* node = list->first;

    while(node != NULL){
        node = node->next;
        n += 1;
    }
    return n;
}

extern void ListInsertInt(List* list, int index, int data){
    assert(list != NULL && list->dataType == INT);
    int* dataPointer = (int*)malloc(sizeof(int));
    assert(dataPointer != NULL);
    *dataPointer = data;
    ListInsert(list, index, dataPointer);
}

extern void ListInsertChar(List* list, int index, char data){
    assert(list != NULL && list->dataType == CHAR);
    char* dataPointer = (char*)malloc(sizeof(char));
    assert(dataPointer != NULL);
    *dataPointer = data;
    ListInsert(list, index, dataPointer);
}

extern void ListInsertBool(List* list, int index, bool data){
    assert(list != NULL && list->dataType == BOOL);
    bool* dataPointer = (bool*)malloc(sizeof(bool));
    assert(dataPointer != NULL);
    *dataPointer = data;
    ListInsert(list, index, dataPointer);
}

extern void ListInsertFloat(List* list, int index, float data){
    assert(list != NULL && list->dataType == FLOAT);
    float* dataPointer = (float*)malloc(sizeof(float));
    assert(dataPointer != NULL);
    *dataPointer = data;
    ListInsert(list, index, dataPointer);
}

extern int ListFetchInt(List* list, int index){
    assert(list != NULL && list->dataType == INT);
    return *(int*)ListFetch(list, index);
}

extern char ListFetchChar(List* list, int index){
    assert(list != NULL && list->dataType == CHAR);
    return *(char*)ListFetch(list, index);
}

extern bool ListFetchBool(List* list, int index){
    assert(list != NULL && list->dataType == BOOL);
    return *(bool*)ListFetch(list, index);
}

extern float ListFetchFloat(List* list, int index){
    assert(list != NULL && list->dataType == FLOAT);
    return *(float*)ListFetch(list, index);
}

extern void ListPrint(List* list){
    assert(list != NULL && list->dataType != STRUCT);
    
    ListNode* node = list->first;

    printf("List :\n");
    while(node != NULL){
        if(list->dataType == INT){printf("%d ",*(int*)node->data);}
        if(list->dataType == FLOAT){printf("%.2f ",*(float*)node->data);}
        if(list->dataType == BOOL){*(bool*)node->data ? printf("true ") : printf("false ");}
        if(list->dataType == CHAR){printf("%c ",*(char*)node->data);}
        node = node->next;
    }
    printf("\n\n");
}