#include<stdio.h>
#include<malloc.h>
void add(int a[], int b[], int c[], int n)
{
    int i;
    for(i=0;i<=n*(n+1)/2-1; i++)
    c[i]=a[i]+b[i];
}
void print(int a[],int n)
{
    int i, j, k;
    for (i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(i>=j) k=i*(i-1)/2+j-1;
            else k=j*(j-1)/2+i-1;
            printf("%d   ", a[k]);
        }
        printf("\n");
    }
}
void main()
{
    int a[]={1,2,3,4,5,6};
    int b[]={10,20,30,40,50,60};
    int c[6];
    int n=3;
    add(a,b,c,n);
    print(c, n);
}