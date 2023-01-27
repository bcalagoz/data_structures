#ifndef stack_linked_list
#define stack_linked_list

struct n
{
    struct n * next;
    int data ;
};
typedef struct n node;

int pop(node*);
node* push(node*,int);
#endif