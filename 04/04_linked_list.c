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
    printf("\n");
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
    return r;
}

int main(){
    node * root;
    root = NULL;

    root = add_in_order(root,400);
    root = add_in_order(root,40);
    root = add_in_order(root,4);
    root = add_in_order(root,450);
    root = add_in_order(root,50);
    print_list(root);
    
    root = delete_node(root,50);
    print_list(root);
    
    root = delete_node(root,999);
    print_list(root);
    
    root = delete_node(root,4);
    print_list(root);
    
    root = delete_node(root,450);
    print_list(root);
    
    return 0;
}
    