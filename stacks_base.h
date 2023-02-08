#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef enum StackTypeEnum{
    CHAR,
    INT,
    FLOAT,
    BOOL,
    STRUCT
} StackType;

typedef struct StackNodeStruct{
    struct StackNodeStruct* next;
    void* data;
} StackNode;

typedef struct StackStruct{
    struct StackNodeStruct* head;
    StackType dataType;
} Stack;

extern Stack* StackCreate(StackType dataType){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    assert(stack != NULL);
    stack->head = NULL;
    stack->dataType = dataType;
    return stack;
}

StackNode* StackNodeCreate(){
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    assert(node != NULL);
    node->data = NULL;
    node->next = NULL;
    return node;
}

extern void StackPile(Stack* stack, void* data){
    assert(stack != NULL);

    StackNode* node = StackNodeCreate();    
    node->data = data;

    node->next = stack->head;
    stack->head = node;
}

extern bool StackIsEmpty(Stack* stack){
    assert(stack != NULL);
    return stack->head == NULL;
}

extern void* StackPop(Stack* stack){
    assert(stack != NULL);
    assert(!StackIsEmpty(stack));
    StackNode* newHead = stack->head->next;
    void* dataToReturn = stack->head->data;

    free(stack->head);
    stack->head = newHead;
    return dataToReturn;
}

extern void* StackPeek(Stack* stack){
    assert(stack != NULL);
    assert(!StackIsEmpty(stack));
    return stack->head->data;
}

extern void StackDelete(Stack* stack){
    assert(stack != NULL);
    assert(!StackIsEmpty(stack) || stack->dataType != STRUCT); //can't free complex structures easily : must be done in main code with a looped StackPop

    while(!StackIsEmpty(stack)){
        free(StackPop(stack));
    }
    free(stack);
}