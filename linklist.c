#include<stdio.h>
#include<malloc.h>
typedef int DataType;
typedef struct Node
{
    DataType data;
    struct Node *next;
}SLNode;
void listinitiate(SLNode **head)
{
    *head=(SLNode *)malloc(sizeof(SLNode));
    (*head)->next=NULL;
}
int listlength(SLNode *head)
{
    int size=0;//init size
    SLNode *p=head;
    while(p->next!=0)
    {
        p=p->next;
        size +=1;
    }
    return size;
}
int listinsert(SLNode *head,int i,DataType x)
{
    SLNode *p,*q;
    int j=-1;
    p=head;
    while(p->next!=NULL&&j<i-1)
    {
        p=p->next;
        j++;
    }if(j!=i-1)
    {
        printf("error");
        return 0;
    }
    q=(SLNode *)malloc(sizeof(SLNode));
    q->data=x;
    q->next=p->next;
    p->next=q;
    return 1;
}
int listget(SLNode *head,int i,DataType *x)
{
    SLNode *p;
    int j=-1;
    p=head;
    while(p->next!=NULL&&j<i)
    {
        p=p->next;
        j++;
    }
    *x=p->data;
    return 1;
}
void main(void)
{
    SLNode *head;
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
