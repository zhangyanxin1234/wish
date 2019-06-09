#include<stdio.h>
#include<malloc.h>
typedef int keytype;
typedef struct 
{
    keytype key
}datatype;
#include "HashList.h"
void main()
{
    HashTable myhash;
    datatype a[]= {180, 750, 600, 430, 541, 900, 460}, item={430};
    int n=7, m=13;
    init(&myhash, m);
    for(int i=0; i<n; i++)
    {
        insert(&myhash, a[i]);
    }
    for(int i=0; i<n; i++)
    {
        int j=find(&myhash, a[i]);

        printf("j=%d   ht[]=%d\n", j, myhash.ht[j].data.key);
    }
}
