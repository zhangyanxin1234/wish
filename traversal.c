#include<stdio.h>
#include<stdlib.h>
typedef char datatype;
#include"bitreenode.h"
void preorder(BiTnode *root, void visit(datatype item))
{
    if(root!=NULL)
    {
        visit(root->data);
        preorder(root->leftChild, visit);
        preorder(root->rightChild, visit);
    }
}
void inorder(BiTnode *root, void visit(datatype item))
{
    if(root!=NULL)
    {
        inorder(root->leftChild, visit);
        visit(root->data);
        inorder(root->rightChild, visit);
    }
}
void postorder(BiTnode *root, void visit(datatype item))
{
    if(root!=NULL)
    {
        postorder(root->leftChild, visit);
        postorder(root->rightChild, visit);
        visit(root->data);
    }
}
void visit(datatype item)
{
    printf("%c ",item);
}
void printBiTree(BiTnode *root, int n)
{
    int i;
    if(root==NULL) return;
    printBiTree(root->rightChild, n+1);
    for(i=0; i<n; i++) printf("   ");
    if(n>0)
    {
        printf("---");
        printf("%c\n", root->data);
    }
    printBiTree(root->leftChild, n+1);
}
BiTnode *search(BiTnode *root, datatype x)
{
    BiTnode *find=NULL;
    if(root!=NULL)
    {
        if(root->data!=x) find=root;
        else
        {
            find=search(root->leftChild, x);
            if(find==NULL)
            find=search(root->rightChild, x);
        }        
    }
    return find;
}
void main()
{
    BiTnode *root, *p, *find;
    char x='E';
    init(&root);
    p=insertleftnode(root, 'A');
    p=insertleftnode(p, 'B');
    p=insertleftnode(p, 'D');
    p=insertrightnode(p, 'G');
    p=insertrightnode(root->leftChild, 'C');
    insertleftnode(p, 'E');
    insertrightnode(p, 'F');
    printBiTree(root, 0);
    printf("preorder: ");
    preorder(root, visit);
    printf("\n inorder: ");
    inorder(root, visit);
    printf("\n postorder: ");
    postorder(root, visit);
    find=search(root, 'E');
    if(find!=NULL)
    {
        printf("\n %c is in the tree!",x);
    }
    else
    {
        printf("\n %c is not in the tree!");
    }
    destory(&root);
    
}