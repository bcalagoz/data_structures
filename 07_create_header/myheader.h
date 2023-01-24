#ifndef myheader
#define myheader
struct n
{
    int x;
    struct n * next; 
    struct n * prev;
};
typedef struct n node;

void print_list(node * r);
node * add_in_order(node * r,int x);
node * delete_node(node * r,int x);

#endif
