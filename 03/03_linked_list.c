#include <stdio.h>
#include <stdlib.h>


struct n
{
    int x;
    struct n * next; 
};
typedef struct n node;

void print_list(node * r){
    while (r != NULL)
    {
        printf("%d ",r->x);
        r = r->next;
    }
}

void add_node(node * r,int x){
    while (r->next != NULL)
    {
        r =r->next;
    }
    r->next = (node*)malloc(sizeof(node));
    r->next->x = x;
    r->next->next = NULL;
}

node * add_in_order(node * r,int x){
    if (r == NULL) //empty linked list
    {
        r = (node *)malloc(sizeof(node *));
        r->x = x;
        r->next = NULL;
        return r;
    }
    else if (r->x > x)//less than the first element
    {
        node * temp = (node*)malloc(sizeof(node));
        temp->x = x;
        temp->next = r;
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
    temp->x = x;
    return r;
}

int main(){
    node * root;
    root = NULL;

    root = add_in_order(root,50);
    root = add_in_order(root,40);
    root = add_in_order(root,45);
    root = add_in_order(root,60);
    print_list(root);
    
    return 0;
}
    