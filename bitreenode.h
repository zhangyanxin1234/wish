#include<stdio.h>
#include<malloc.h>
typedef char datatype;
typedef struct node
{
    datatype data;
    struct node *leftChild;
    struct node *rightChild;
}BiTnode;
void init(BiTnode **root)
{
    *root=(BiTnode *)malloc(sizeof(BiTnode));
    (*root)->leftChild=NULL;
    (*root)->rightChild=NULL;
}
