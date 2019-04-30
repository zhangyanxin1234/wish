#include<stdio.h>
#include<malloc.h>
typedef int DataType;
typedef struct Dulinklist
{
    DataType data;
    struct node *next;
    struct node *prior;
}dlnode;
void listinitiate(dlnode **head)
{
    *head=(dlnode *)malloc(sizeof(dlnode));
    (*head)->next=*head;
    (*head)->prior=*head;
}
int listinsert(dlnode *head,int i,DataType x)
{
    dlnode *p,*s,*m;
    p=(dlnode *)malloc(sizeof(dlnode *));
    int j=-1;
    p=head;
    while(p!=head&&j<i)
    {
        p=p->next;
        j++;
    }
    s=(dlnode *)malloc(sizeof(dlnode));
    s->data=x;
    s->prior=p->prior;
    m=p->prior;
    m->next=s;
    s->next=p;
    p->prior=s;
    return 1;
}
int listget(dlnode *head,int i,DataType *x)
{
    dlnode *p;
    p=head;
    int j=-1;
    while(j<i)
    {
        p=p->next;
        j++;
    }
    *x=p->data;
    return 1;
}
int listlength(dlnode *head)
{
    dlnode *p=head;
    int size=0;
    while(p->next!=head)
    {
        size++;
        p=p->next;
    }
    return size;
}
void main()
{
        dlnode *head;
    int i,x;
    listinitiate(&head);
    for(i=0;i<10;i++)
    {
        listinsert(head,i,i+1);
    };
    for(i=0;i<listlength(head);i++)
    {
        listget(head,i,&x);
        printf("%d   ",x);
    };
}
