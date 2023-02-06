#include<stdio.h>
#include<stdlib.h>

struct n{
    int data;
    struct n * left;
    struct n * right;
};
typedef struct n node;

node * insert(node * tree,int a){
    if (tree == NULL)
    {
        tree = (node*)malloc(sizeof(node));
        tree->data = a;
        tree->left = NULL;
        tree->right = NULL;
        return tree;
    }
    if (a > tree->data)
    {
        tree->right = insert(tree->right,a);
        return tree;
    }
    tree->left = insert(tree->left,a);
    return tree;
}

void traverse(node* tree){
    if (tree==NULL)
        return;

    traverse(tree->left);
    printf("%d ",tree->data);
    traverse(tree->right);   
}

int find(node* tree,int a){
    if (tree==NULL)
        return -1;
    if (tree->data == a)
    {
        return 1;
    }
    if (find(tree->right,a) == 1)
    {
        return 1;
    }
    if (find(tree->left,a) == 1)
    {
        return 1;
    }
    return -1;
}

int max(node* tree){
    while (tree->right != NULL)
    {
        tree = tree->right;
    }
    return tree->data;
}

int min(node* tree){
    while (tree->left != NULL)
    {
        tree = tree->left;
    }
    return tree->data;
}

node * delete(node* tree,int a){
    if (tree == NULL)
        return NULL;
    if (tree->data == a)
    {
        if (tree->left == NULL && tree->right ==NULL)
            return NULL;
        if (tree->right != NULL)
        {
            tree->data = min(tree->right);
            tree->right = delete(tree->right,min(tree->right));
            return tree;
        }
        tree->data = max(tree->left);
        tree->left = delete(tree->left,max(tree->left));
        return tree;
    }
    if (a > tree->data)
    {
        tree->right = delete(tree->right,a);
        return tree;
    }
    tree->left = delete(tree->left,a);
    return tree;
}

int main(){
    node * tree = NULL;
    tree = insert(tree,56);
    tree = insert(tree,26);
    tree = insert(tree,200);
    tree = insert(tree,190);
    tree = insert(tree,213);
    tree = insert(tree,18);
    tree = insert(tree,28);
    tree = insert(tree,12);
    tree = insert(tree,24);
    tree = insert(tree,27);

    traverse(tree);
    
    printf("Max:%d  Min:%d\n",max(tree),min(tree));
    
    delete(tree,56);
    traverse(tree);
    return 0;
}