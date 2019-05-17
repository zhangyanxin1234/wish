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
BiTnode *insertleftnode(BiTnode *curr, datatype x)
{
    BiTnode *s, *t;
    if(curr==NULL) return NULL;
    t=curr->leftChild;
    s=(BiTnode *)malloc(sizeof(BiTnode));
    s->leftChild=t;
    curr->leftChild=s;
    s->data=x;
    s->rightChild=NULL;
    return curr->leftChild;
}
BiTnode *insertrightnode(BiTnode *curr, datatype x)
{
    BiTnode *s, *t;
    if(curr==NULL) return NULL;
    t=curr->rightChild;
    s=(BiTnode *)malloc(sizeof(BiTnode));
    s->rightChild=t;
    curr->rightChild=s;
    s->data=x;
    s->leftChild=NULL;
    return curr->rightChild;
}
void destory(BiTnode **root)
{
    if((*root)!=NULL&&(*root)->leftChild!=NULL)
    destory(&(*root)->leftChild);
    if((*root)!=NULL&&(*root)->rightChild!=NULL)
    destory(&(*root)->rightChild);
    free(*root);
}
BiTnode *deletelefttree(BiTnode *curr)
{
    if(curr==NULL||curr->leftChild==NULL) return NULL;
    destory(&curr->leftChild);
    curr->leftChild=NULL;
    return curr;
}
BiTnode *deleterighttree(BiTnode *curr)
{
    if(curr==NULL||curr->rightChild==NULL) return NULL;
    destory(&curr->rightChild);
    curr->rightChild=NULL;
    return curr;
}
