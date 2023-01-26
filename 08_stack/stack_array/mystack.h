#ifndef mystack
#define mystack
struct s
{
    int * array;
    unsigned int size;
    int top;
};
typedef struct s Stack;

Stack * init_stack();
void push(Stack *, int);
int pop(Stack *);
void print_stack(Stack *);
#endif