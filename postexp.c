#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<malloc.h>
typedef int datatype;
typedef struct 
{
    datatype data;
    struct snode *next;
}lsnode;
void stackinitiate(lsnode **head)
{
    *head=(lsnode *)malloc(sizeof(lsnode));
    (*head)->next=NULL;
}
int stacknotempty(lsnode *head)
{
    if(head->next==NULL)
    return 0;
    else return 1;
}
void stackpush(lsnode *head,datatype x)
{
    lsnode *p;
    p=(lsnode *)malloc(sizeof(lsnode));
    p->data=x;
    p->next=head->next;
    head->next=p;
}
int stackpop(lsnode *head,datatype *d)
{
    lsnode *p;
    p=head->next;
    if(p==NULL)
    {
        printf("stack is null!/n");
        return 0;
    }
    head->next=p->next;
    *d=p->data;
    free(p);
    return 1;
}
int stacktop(lsnode *head,datatype *d)
{
    lsnode *p;
    p=head->next;
    *d=p->data;
    return 1;
}
int postexp(char str[])
{
    lsnode *head;
    stackinitiate(&head);
    datatype x,x1,x2;
    for(int i=0;str[i]!='#';i++)
    {
        if(isdigit(str[i]))
        {
            x=(int)(str[i]-48);
            stackpush(head,x);
        }
        else
        {
            stackpop(head, &x2);
            stackpop(head, &x1);
            switch(str[i])
            {
                case '+': {x1 += x2; break; }
                case '-': {x1 -= x2; break; }
                case '*': {x1 *= x2; break; }
                case '/': 
                if(x2==0)
                {
                    printf("error!/n");
                    exit(0);
                }
                else
                {
                    x1/=x2;
                    break;
                }                
            }
            stackpush(head,x1); 
        }        
    }
    stackpop(head,&x);
    return x;
}
void main(void)
{
    char str[]="3642/-5*+#";
    int result;
    result=postexp(str);
    printf("%d", result);
}
