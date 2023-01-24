#include <stdio.h>
#include <stdlib.h>
#include "myheader.h"


void print_list(node * r){
    while (r != NULL)
    {
        printf("%d ",r->x);
        r = r->next;
    }
    printf("\n");
}

node * add_in_order(node * r,int x){
    if (r == NULL) //empty linked list
    {
        r = (node *)malloc(sizeof(node *));
        r->x = x;
        r->next = NULL;
        r->prev = NULL;
        return r;
    }
    else if (r->x > x)//less than the first element
    {
        node * temp = (node*)malloc(sizeof(node));
        temp->x = x;
        temp->next = r;
        r->prev = temp;
        temp->prev = NULL;
        return temp;
    }
    node * iter = r;
    while (iter->next != NULL && iter->next->x < x)
    {
        iter =iter->next;
    }
    node * temp = (node*)malloc(sizeof(node));
    temp->next = iter->next;
    iter->next = temp;
    temp->prev = iter;
    if (temp->next != NULL)
    {
        temp->next->prev = temp; 
    }
    temp->x = x;
    return r;
}

node * delete_node(node * r,int x){
    node * iter = r;
    node * temp;

    if (r->x == x)
    {
        temp = r;
        r = r->next;
        free(temp);
        return r;
    }
    while (iter->next != NULL && iter->next->x != x)
    {
        iter = iter->next;
    }
    if (iter->next == NULL)
    {
        printf("NOT FOUND\n");
        return r;
    }
    
    temp = iter->next;
    iter->next = iter->next->next;
    free(temp);
    if (iter->next != NULL)
    {
        iter->next->prev = iter; 
    }
    return r;
}