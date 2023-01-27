#include <stdio.h>
#include <stdlib.h>
#include "stack_linked_list.h"

int main(){
    node * s = NULL;
    
    s = push(s,10);
    s = push(s,20);
    s = push(s,30);

    printf("%d ",pop(s));
    s = push(s,40);
    printf("%d ",pop(s));
    printf("%d ",pop(s));

    return 0;
}