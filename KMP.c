#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef struct 
{
    char *str;
    int maxlength;
    int length;
}dstring;
void initiate(dstring *S,int max,char *string)
{
    int i;
    S->str=(char *)malloc(sizeof(char)*max);
    S->maxlength=max;
    S->length=strlen(string);
    for(i=0;i<S->length;i++)
    {
        S->str[i]=string[i];     
    }
}
/*int insert(dstring *S,int pos,dstring T)
{
    int i;
    if(S->length+T.length>S->maxlength)
    {
        realloc(S->str,(S->length+T.length)*sizeof(char));
        S->maxlength=S->length+T.length;
    }
    for(i=S->length-1;i>=pos;i--)
    {
        S->str[i+T.length]=S->str[i];
    }
    for(i=0;i<T.length;i++)
    {
        S->str[pos+i]=T.str[i];
    }
    S->length+=T.length;
    return 1;
}*/
int delete(dstring *S,int pos, int len)
{
    int i;
    for(i=pos+len; i<=S->length-1; i++)
    {
        S->str[i-pos]=S->str[i];
    }
    S->length-=len;
    return 1;
}int substring(dstring *S,int pos,int len, dstring *T)
{
    if(len>T->length)
    {
        T->str=(char *)malloc(len*sizeof(char));
        T->maxlength=len;
    }
    for(int i=0;i<len;i++)
    T->str[i]=S->str[i+pos];
    T->length=len;
    return 1;
}
void getnext(dstring S,int next[])
{
    int j=1, k=0;
    next[0]=-1;
    next[1]=0;
    while(j<S.length-1)
    {
        if(S.str[j]==S.str[k])
        {
            next[j+1]=k+1;
            k++;
            j++;
        }
        else if(k==0)
        {
            next[j+1]=0;
            j++;
        }
        else k=next[k];
    }
}
int KMPindex(dstring S,int start, dstring T, int next[])
{
    int i=start, j=0, v;
    while(i<S.length&&j<T.length)
    {
        if(S.str[i]==T.str[j])
        {
            i++;
            j++;
        }
        else if(j==0) i++;
        else j=next[j];
    }
    if(j==T.length) v=i-T.length;
    else v=-1;
    return v;
}
void main(void)
{
    dstring string1, string2;
    int max1=30, max2=10;
    int pos=0;
    int next[29];
    initiate(&string1, max1,"Data Structure Data Structure");
    initiate(&string2, max2, "Structure");
    getnext(string2, next);
    pos=KMPindex(string1, pos, string2, next);
    printf("pos=%d\n", pos);
    pos=KMPindex(string1, pos+1, string2, next);
    printf("pos=%d\n", pos);
}
