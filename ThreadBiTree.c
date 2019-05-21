#include<stdio.h>
#include<malloc.h>
typedef char datatype;
typedef struct node
{
    datatype data;
    int leftthread;
    struct node *leftchild;
    int rightthread;
    struct node *rightchild;
}threadbinode;
void creatinthread(threadbinode **root)
{
    threadbinode *t= *root;     //change
    threadbinode *current, *pre=*root;
    *root=(threadbinode *)malloc(sizeof(threadbinode));
    if(t==NULL)
    {
        (*root)->leftthread=0;
        (*root)->rightthread=1;
        (*root)->leftchild=*root;
        (*root)->rightchild=*root;
    }
    else
    {
        current=t;
        (*root)->leftchild=t;
        (*root)->leftthread=0;
        inthread(current, &pre);
        pre->rightchild=*root;
        pre->leftthread=1;
        (*root)->rightchild=pre;
        (*root)->rightthread=1;
    }
    
}
void inthread(threadbinode *current, threadbinode **pre)
{
    if(current!=NULL)
    {
        inthread(current->leftchild, pre);
        if(current->leftchild==NULL)
        {
            current->leftthread=1;
            current->leftchild=*pre;
        }
        else
        current->leftthread=0;
        if(current->rightchild!=NULL)
        current->rightthread=0;
        else
        {
            current->rightthread=1;
        }
        if((*pre)->rightchild==NULL)
        {
            (*pre)->rightthread=1;
            (*pre)->rightchild=current;
        }
        else (*pre)->rightthread=0;   
        *pre=current;
        inthread(current->rightchild, pre);
    }
}
typedef struct 
{
    threadbinode *root;
    threadbinode *current;
    int nextcomplete;
}threadbitree;
void threadinit(threadbitree *tree, threadbinode *root)
{
    tree->root=root;
    tree->current=root;
    if(root==NULL) tree->nextcomplete=1;
    else tree->nextcomplete=0;
}
void first(threadbitree *tree)
{
    tree->current=tree->root;
    while(tree->current->leftthread==0)
    tree->current=tree->current->leftchild;
    if(tree->current==tree->root)
    tree->nextcomplete=1;
    else
    tree->nextcomplete=0;    
}
void next(threadbitree *tree)
{
    threadbinode *p=tree->current->rightchild;
    if(tree->nextcomplete==1) return;
    if(tree->current->rightthread==0)
    while(p->leftthread==0) p=p->leftchild;
    tree->current=p;
    if(tree->current==tree->root)
    tree->nextcomplete=1;
}
int endofnext(threadbitree *tree)
{
    return tree->nextcomplete;
}
threadbinode *gettreenode(datatype item, threadbinode *left, threadbinode *right)
{
    threadbinode *p;
    p=(threadbinode *)malloc(sizeof(threadbinode));
    p->data=item;
    p->leftchild=left;
    p->rightchild=right;
    return p;
}
void makechartree(threadbinode **root)
{
    threadbinode *b, *c, *d, *e, *f, *g;
    g=gettreenode('G', NULL, NULL);
    d=gettreenode('D', NULL, g);
    b=gettreenode('B', d, NULL);
    e=gettreenode('E', NULL, NULL);
    f=gettreenode('F', NULL, NULL);
    c=gettreenode('C', e, f);
    *root=gettreenode('A', b, c);
}
void main()
{
    threadbinode *root;
    threadbitree tree;
    makechartree(&root);
    creatinthread(&root);
    printf("result: ");
    threadinit(&tree, root);
    for(first(&tree); !endofnext(&tree); next(&tree))
    printf("%c ", tree.current->data);
}