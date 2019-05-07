#include<stdio.h>
#include<string.h>
typedef char datatype;
#define maxstacksize 100
typedef struct {
    datatype stack[maxstacksize];
    int top;
}seqstack;
void stackinitiate(seqstack *S)
{
    S->top=0;
}
int stackpush(seqstack *S,datatype x)
{
    S->stack[S->top]=x;
    S->top++;
    return 1;
}
int stackpop(seqstack *S,datatype *d)
{
    S->top--;
    *d=S->stack[S->top];
    return 1;
}
int stacktop(seqstack S,datatype *d)
{
    *d=S.stack[S.top-1];
    return 1;
}
int stacknotempty(seqstack S)
{
    if(S.top<=0)
    return 0;
    else 
    return 1;
}
void expiscorrect(char exp[],int n)
{
    seqstack mystack;
    int i;
    char c;
    stackinitiate(&mystack);
    for(i=0;i<n;i++)
    {
        if((exp[i]=='(')||(exp[i]=='[')||(exp[i]=='{'))
        stackpush(&mystack,exp[i]);
               else if((exp[i]==')')&&stacknotempty(mystack)&&(stacktop(mystack,&c))&&c=='(')
        stackpop(&mystack,&c);
        else if((exp[i]==')')&&stacknotempty(mystack)&&(stacktop(mystack,&c))&&c!='(')
        {
            printf("error!\n");
            return;
        }
        else if((exp[i]==']')&&stacknotempty(mystack)&&(stacktop(mystack,&c))&&c=='[')
        stackpop(&mystack,&c);
        else if((exp[i]==']')&&stacknotempty(mystack)&&(stacktop(mystack,&c))&&c!='[')
        {
            printf("error!\n");
            return;
        }
        else if((exp[i]=='}')&&stacknotempty(mystack)&&(stacktop(mystack,&c))&&c=='{')
        stackpop(&mystack,&c);
        else if((exp[i]=='}')&&stacknotempty(mystack)&&(stacktop(mystack,&c))&&c!='{')
        {
            printf("error!\n");
            return;
        }
        else if(((exp[i]==')'||(exp[i]==']')||(exp[i]=='}')))&&!stacknotempty(mystack))
        {
            printf("right is more than left!\n");
            return;
        }
    }
    if(stacknotempty(mystack))
    printf("left is more than right!\n");
    else
    printf("it is right!\n");   
}
void main(void)
{
    char a[]="(())abc{[]()}";
    char b[]="(()))abc{[]}";
    char c[]="(()()abc{[]}";
    char d[]="(())abc{[]}";
    int n1=strlen(a);
    int n2=strlen(b);
    int n3=strlen(c);
    int n4=strlen(d);
    expiscorrect(a,n1);
    expiscorrect(a,n2);
    expiscorrect(a,n3);
    expiscorrect(a,n4);
}