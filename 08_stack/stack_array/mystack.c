#include<stdio.h>
#include<stdlib.h>
#include "mystack.h"



Stack * init_stack(){
    Stack * a = (Stack*)malloc(sizeof(Stack));
    a->size = 2;
    a->array =(int*)malloc(sizeof(int)*2);;
    a->top = 0;

    return a;
}
// Function to add an item to stack.  It increases top by 1.
void push(Stack *s, int x){
    if (s->array == NULL)
    {
        s->array = (int*)malloc(sizeof(int)*2);
    }
    if (s->top >= s->size-1)
    {
        int * array2 = (int *)malloc(sizeof(int)*s->size*2);
        for (int i = 0; i < s->size; i++)
        {
            array2[i] = s->array[i];
        }
        int * temp = s->array;
        free(temp);
        s->array = array2;
        s->size *= 2;
    }
    s->array[s->top++] = x;
}

// Function to remove an item from stack.  It decreases top by 1
int pop(Stack *s){
    if (s->array == NULL || s->top <= 0)
    {
        printf("Stack is empty!\n");
        return -1;
    }
    if (s->top <= s->size/4 && s->size > 2)
    {
        int * array2 = (int*)malloc(sizeof(int)*s->size/2);
        for (int i = 0; i < s->top; i++)
        {
            array2[i] = s->array[i];
        }
        int * temp = s->array;
        free(temp);
        s->array = array2;
        s->size /= 2;
    }
    return s->array[--s->top];
}

void print_stack(Stack * s){
    for (int i = 0; i < s->top; i++)
    {
        printf("%d ",s->array[i]);
    }
    printf("\n");
}
