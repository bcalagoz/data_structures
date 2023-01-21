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

int main(){
    node * root;
    root = (node *)malloc(sizeof(node));
    root -> x = 10;
    root -> next = NULL;

    node * iter = root;

    for (int i = 0; i < 5; i++)
    {
        add_node(iter,i*100);
    }
    
    print_list(root);

    return 0;

}
    