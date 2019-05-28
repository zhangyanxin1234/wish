#include<stdio.h>
typedef int KeyType;
typedef struct 
{
    KeyType key
}datatype;
typedef struct node
{
    datatype data;
    struct node *leftchild;
    struct node *rightchild;
}BiTreeNode;
int Search(BiTreeNode *root, datatype item)
{
    BiTreeNode *p;
    if(root!=NULL)
    {
        p=root;
        while(p!=NULL)
        {
            if(p->data.key==item.key) return 1;
            if(item.key>p->data.key) p=p->rightchild;
            else p=p->leftchild;
        }
    }
    return 0;
}
int Insert(BiTreeNode **root, datatype item)
{
    BiTreeNode *current=*root;
    BiTreeNode *parent=NULL;
    while(current!=NULL)
    {
        if(current->data.key==item.key) return 0;
        parent=current;
        if(current->data.key<item.key) current=current->rightchild;
        else current=current->leftchild;
    }
    BiTreeNode *p=(BiTreeNode *)malloc(sizeof(BiTreeNode));
    p->data=item;
    p->leftchild=NULL;
    p->rightchild=NULL;
    if(parent ==NULL) *root=p;
    else if(parent->data.key<item.key)
    parent->rightchild=p;
    else if(parent->data.key>item.key)
    parent->leftchild=p;
    return 1;
}
void InTraverse(BiTreeNode *root)
{
    if(root==NULL) return ;
    if(root->leftchild!=NULL)
    InTraverse(root->leftchild);
    printf("%d   ",root->data.key);
    if(root->rightchild!=NULL)
    InTraverse(root->rightchild);
}
void main()
{
    datatype test[]={4,5,7,56,6,8,1,2,9}, x={7};
    int n=9, i,s ;
    BiTreeNode *root=NULL;
    for(i=0; i<n; i++)
    {
        Insert(&root, test[i]);
    }
    InTraverse(root);
    s=Search(root, x);
    if(s==1)
    printf("\ndata %d can find");
    else 
    printf("\ndata %d can not find");
}