#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef enum ListTypeEnum{
    CHAR,
    INT,
    FLOAT,
    BOOL,
    STRUCT
} ListType;

typedef struct ListNodeStruct{
    struct ListNodeStruct* next;
    void* data;
} ListNode;

typedef struct ListStruct{
    struct ListNodeStruct* first;
    ListType dataType;
} List;

extern List* ListCreate(ListType dataType){
    List* list = (List*)malloc(sizeof(List));
    assert(list != NULL);
    list->first = NULL;
    list->dataType = dataType;
    return list;
}

ListNode* ListNodeCreate(){
    ListNode* listNode = (ListNode*)malloc(sizeof(ListNode));
    assert(listNode != NULL);
    listNode->data = NULL;
    listNode->next = NULL;
    return listNode;
}

extern void ListInsert(List* list, int index, void* data){
    assert(list != NULL);
    assert(index >= 0);

    ListNode* newNode = ListNodeCreate();
    ListNode* previousNode = list->first;
    int n = 0;
    
    newNode->data = data;

    if(index == 0){
        newNode->next = list->first;
        list->first = newNode;
    }
    else{
        n = 1;
        while(n < index && previousNode != NULL){
            previousNode = previousNode->next;
            n++;
        }
        assert(previousNode != NULL);
        newNode->next = previousNode->next;
        previousNode->next = newNode;
    }
}

extern void* ListFetch(List* list, int index){
    assert(list != NULL);
    assert(index >= 0);

    ListNode* node = list->first;
    int n = 0;
    while(n < index && node != NULL){
        node = node->next;
        n++;
    }
    assert(node != NULL);
    return node->data;
}

extern void* ListRemove(List* list, int index){
    assert(list != NULL);
    assert(index >= 0);

    ListNode* node = list->first;
    ListNode* previousNode = NULL;
    void* dataToReturn = NULL;
    int n = 0;

    if(index == 0 && list->first != NULL){
        list->first = node->next;
        dataToReturn = node->data;
        free(node);
    }
    else{
        n = 1;
        assert(list->first != NULL);
        previousNode = list->first;
        node = previousNode->next;
        while(n < index && node != NULL){
            previousNode = previousNode->next;
            node = node -> next;
            n++;
        }
        assert(node != NULL);
        previousNode->next = node->next;
        dataToReturn = node->data;
        free(node);
    }
    
    if(list->dataType != STRUCT){
        free(dataToReturn);
        return NULL;
    }else{
        return dataToReturn;
    }
}

extern void ListDelete(List* list){
    assert(list != NULL);
    assert(list->first == NULL || list->dataType != STRUCT); //can't free complex structures easily : must be done in main code with a looped ListRemove

    ListNode* node = list->first;
    ListNode* next = NULL;
    while(node != NULL){
        free(node->data);
        next = node->next;
        free(node);
        node = next;
    }
    free(list);
}