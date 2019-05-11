#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef int datatype;
typedef struct node
{
    char *text;
    int id;
    struct node *next;
}lqnode;
typedef struct 
{
    lqnode *front;
    lqnode *rear;
}lqueue;
void queueinit(lqueue *Q)
{
    Q->front=NULL;
    Q->rear=NULL;
}
int queuenotempty(lqueue Q)
{
    if(Q.front==NULL) return 0;
    else return 1;
}
void queueappend(lqueue *Q,int tid, char *text)
{
    lqnode *p;
    p=(lqnode *)malloc(sizeof(lqnode));
    p->text=text;
    p->id=tid;
    p->next=NULL;
    if(Q->rear!=NULL) Q->rear->next=p;
    Q->rear=p;
    if(Q->front==NULL) Q->front=p;
}
int queuedelete(lqueue *Q)
{
    lqnode *p;
    if(Q->front==NULL)
    {
        printf("The queue is empty!/n");
        return 0;
    }
    else
    {
        p=Q->front;
        printf("Task id: %d\n", p->id);
        printf("task cotext: %s\n", p->text);
        Q->front=p->next;
        if(Q->front==NULL) Q->rear=NULL;
        free(p);
        return 1;
    }
}
/*int queueget(lqueue Q,datatype *d)
{
    if(Q.front==NULL)
    {
        printf("The queue is empty");
        return 0;
    }
    else
    {
        *d=Q.front->data;
        return 1;
    }  
}*/
void printalltask(lqueue *Q)
{
    lqnode *p=Q->front;
    while(p!= NULL)
    {
        printf("Task id: %d\n", p->id);
        printf("task cotext: %s\n", p->text);
        p=p->next;
    }
}
void main(void)
{
    char ch='0';
    int tid=0;
    char *text="context";
    lqueue *Q;
    queueinit(&Q);
    while(ch!='q')
    {
        printf("1   join");
        printf("\t2   finish");
        printf("\t3   show the queue");
        printf("\tq   exit");
        printf("\nPlease enter:");
        ch=getchar();
        getchar();
        switch(ch)
        {
            case '1':
            tid=tid+1;
            queueappend(&Q,tid,text);
            break;
            case '2':
            queuedelete(&Q);
            break;
            case '3':
            printalltask(&Q);
            break;
            case 'q':
            return;
        }
    }
}