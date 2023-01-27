#include <stdio.h>
#include <stdlib.h>
#include "stack_linked_list.h"

node * push(node* root, int a){
    if (root == NULL)
    {
        root = (node*)malloc(sizeof(node));
        root->data = a;
        root->next = NULL;
        return root;
    }
    node* iter = root;
    while (iter->next != NULL)
    {
        iter = iter->next;
    }
    node* temp = (node*)malloc(sizeof(node));
    temp->data = a;
    temp->next = NULL;
    iter->next = temp;
    return root;
}

int pop(node* root){
    if (root == NULL)
    {
        printf("Stack is empty!\n");
        return -1;
    }
    else if (root->next == NULL)
    {
        int rvalue = root->data;
        root = NULL;
        return rvalue;
    }
    
    node* iter = root;
    while (iter->next->next != NULL)
    {
        iter = iter->next;
    }
    int rvalue = iter->next->data;
    free(iter->next);
    iter->next = NULL;
    return rvalue;
}


