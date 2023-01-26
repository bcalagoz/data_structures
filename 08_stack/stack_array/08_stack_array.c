#include<stdio.h>
#include<stdlib.h>
#include "mystack.h"

int main(){
    Stack * s1 = init_stack();
    Stack * s2 = init_stack();

    for (int i = 0; i < 10 ; i++)
    {
        push(s1,i);
    }
    print_stack(s1);
    for (int i = 0; i < 10; i++)
    {
        push(s2,pop(s1));
    }

    print_stack(s1);
    print_stack(s2);
    
    return 0;
}