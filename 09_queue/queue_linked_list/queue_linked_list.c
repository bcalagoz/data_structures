#include<stdio.h>
#include<stdlib.h>

struct n
{
    struct n * next;
    int data ;
};
typedef struct n node;



node* enque(node* root, int a){
    if (root == NULL)
    {
        root = (node*)malloc(sizeof(node));
        root->data = a;
        root->next = NULL ;
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

int deque(node* root){
    printf("test\n");
    if (root = NULL)
    {
        printf("Queue is empty!\n");
        printf("test1\n");
        return -1;
    }
    printf("test2\n");
    int rvalue = root->data;
    printf("test3\n");
    node* iter = root;
    printf("test4\n");
    root = root->next;
    printf("test5\n");
    free(iter);
    printf("test6\n");
    return rvalue;
    
}


int main(){

    node * s = NULL;
    printf("%d ",deque(s));
    

    
    /*
    for (int i = 0; i < 20; i++)
    {
        s =enque(s,i*10);
    }
    for (int i = 0; i < 20; i++)
    {
        printf("%d  ",s->data);
        s = s->next;
    }
    
    
    
    for (int i = 0; i < 13; i++)
    {
        printf("%d  ",deque(s));
    }
    
    for (int i = 0; i < 20; i++)
    {
        s = enque(s,i*10);
    }
    for (int i = 0; i < 30; i++)
    {
        printf("%d  ",deque(s));
    }
    */

    return 0;
}


