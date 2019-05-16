#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef char datatype;
typedef struct Glistnode
{
    int tag;
    union 
    {
        datatype atom;
        struct
        {
            struct Glistnode *head;
            struct Glistnode *tail; 
        }sublist;
    }val;    
}Glnode;
void decomposestr(char str[], char hstr[])
{
    int i, j, tag, n=strlen(str);
    char ch;
    ch=str[0]; 
    tag=0;
    for(i=0; i<=n-1; i++)
    {
        if(str[i]==','&&tag==1)        
        break;
        ch=str[i];
        if(ch=='(') tag++;
        if(ch==')') tag--;
    }
    if(i<=n-1&&str[i]==',')
    {
        for(j=0; j<i-1; j++)
        {
            hstr[j]=str[j+1];
        }
        hstr[j]='\0';
        if(str[i]==',') i++;
        str[0]='(';
        for(j=1; i<=n-2; i++,j++)
        {
            str[j]=str[i];
        }
        str[j]=')';
        str[++j]='\0';
    }
    else 
    {
        str++;
        strcpy(hstr, str);
        hstr[n-2]='\0';
        str--;
        strcpy(str, "()");
    }
}
Glnode* creatglist(char str[])
{
    Glnode *h;
    char hstr[200];
    int len=strlen(str);
    if(strcmp(str, "()")==0) h=NULL;
    else if(len ==1)
    {
        h=(Glnode *)malloc(sizeof(Glnode));
        h->tag=0;
        h->val.atom=str[0];
    }
    else
    {
        h=(Glnode *)malloc(sizeof(Glnode));
        h->tag=1;
        decomposestr(str, hstr);
        h->val.sublist.head=creatglist(hstr);
        if(strcmp(str, "()")!=0)
        h->val.sublist.tail=creatglist(str);
        else
        h->val.sublist.tail=NULL;      
    }
    return h;
}
void main()
{
    char str[]="(a)";
    char hstr[100];
    Glnode *h;
    h=creatglist(str);
    /*decomposestr(str,hstr);
    printf("hstr=%s",hstr);
    printf("   str=%s",str);*/
    //char b=h->val.atom;
    printf("%c",h->val.sublist.tail);
    
}
