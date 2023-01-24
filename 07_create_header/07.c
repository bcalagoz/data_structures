//DOUBLY LINKED LIST
#include <stdio.h>
#include <stdlib.h>
#include "myheader.h"


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
    