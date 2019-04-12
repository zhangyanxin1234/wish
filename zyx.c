#include<stdio.h>
#define maxsize 100
typedef struct {
    int list[maxsize];
    int size;
}A;
void listinitiate(A *L)
{
    L->size=0;
}
void listinsert(A *L,int i,int x)
{
    int j;
    for(j=L->size;j>i;j--){
        L->list[j]=L->list[j-1];
    }
    L->list[i]=x;
    L->size++;
}
void listget(A L,int i,int *x)
{
    *x=L.list[i];
}
void main()
{
    A zyx;
    int i,x,y;
    int z=3;
    listinitiate(&zyx);
    for(i=0;i<10;i++)
    {
        listinsert(&zyx,i,i+1);
    }
    listget(zyx,z,&y);
    printf("%d",y);
    //printf("hello");
    //system("pause");
}