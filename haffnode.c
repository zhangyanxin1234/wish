#include<stdio.h>
#include<stdlib.h>
#define MaxValue 10000
#define Maxbit 4
typedef struct 
{
    int weight;
    int flag;
    int parent;
    int leftChild;
    int rightChild;
}HaffNode;
typedef struct 
{
    int bit[Maxbit];
    int start;
    int weight;
}Code;
void Haffman(int weight[], int n, HaffNode haffTree[])
{
    int i;
    //init hafftree
    for(i=0; i<2*n-1; i++)
    {
        if(i<n) haffTree[i].weight=weight[i];
        else haffTree[i].weight=0;
        haffTree[i].flag=0;
        haffTree[i].parent=-1;
        haffTree[i].leftChild=-1;
        haffTree[i].rightChild=-1;
    }
    //creat hafftree
    for(i=0; i<n-1; i++)
    {
        int m1=MaxValue, m2=MaxValue;
        int x1=0, x2=0;
        //find the smallest and the second smallest tree
        for(int j=0; j<n+i; j++)
        {
            if(haffTree[j].weight<m1&&haffTree[j].flag==0)
            {
                m2=m1;
                x2=x1;
                m1=haffTree[j].weight;
                x1=j;
            }
            else if(haffTree[j].weight<m2 && haffTree[j].flag==0)
            {
                m2=haffTree[j].weight;
                x2=j;
            }
        }
        haffTree[x1].parent=n+i;
        haffTree[x2].parent=n+i;
        haffTree[x1].flag=1;
        haffTree[x2].flag=1;
        haffTree[n+i].weight=haffTree[x1].weight+haffTree[x2].weight;
        haffTree[n+i].leftChild=x1;
        haffTree[n+i].rightChild=x2;
    }
}

void HaffmanCode(HaffNode haffTree[], int n, Code haffCode[])
{
    //creat haffcode by hafftree
    Code *cd=(Code *)malloc(sizeof(Code));
    int i,j ,child, parent;
    for(i=0; i<n; i++)
    {
        cd->start= n-1;
        cd->weight=haffTree[i].weight;
        child=i;
        parent=haffTree[child].parent;
        while(parent!=-1)
        {
            if(haffTree[parent].leftChild==child)
            cd->bit[cd->start]=0;
            else
            cd->bit[cd->start]=1;
            cd->start--;
            child=parent;
            parent=haffTree[child].parent;
        }
        for(j=cd->start+1; j<n; j++)
        {
            haffCode[i].bit[j]=cd->bit[j];
        }
        haffCode[i].start=cd->start+1;
        haffCode[i].weight=cd->weight;
    }
}
void main()
{
    int i, j ,n=4;
    int weight[]={1,5,8,9};
    HaffNode *myhafftree=(HaffNode *)malloc(sizeof(HaffNode)*(2*n-1));
    Code *mycode=(Code *)malloc(sizeof(Code)*n);
    Haffman(weight, n, myhafftree);
    HaffmanCode(myhafftree, n, mycode);
    for(i=0; i<n; i++)
    {
        printf("weight=%d Code= ",myhafftree[i].weight);
        for(j=mycode[i].start; j<n; j++)
        {
            printf("%d", mycode[i].bit[j]);
        }
        printf("\n");
    }
}


