//typedef int datatype;
typedef enum
{Empty, Active, Delete} KindOfItem;

typedef struct 
{
    datatype data;
    KindOfItem info;
}HashItem;

typedef struct 
{
    HashItem *ht;
    int tablesize;
    int currentsize;
}HashTable;

int init(HashTable *hash, int msize)
{
    hash->tablesize=msize;
    hash->ht=(HashItem *)malloc(sizeof(HashItem)*msize);
    if(hash->ht==NULL) 
    return 0;
    else
    {
        hash->currentsize=0;
        return 1;
    }
}

int find(HashTable *hash, datatype x)
//return data x's address
//if find it successfully,the return is a positive value
//if find it false,the return is a negative value
{
    int i=x.key % hash->tablesize;
    int j = i;
    while(hash->ht[j].info ==Active && hash->ht[j].data.key != x.key)
    //have conflict
    {
        j=(j+1) % hash->tablesize;
        if(j==i)   //can not find and the table is full
        return -hash->tablesize;
    }
    if(hash->ht[j].info == Active)
    return j;
    else
    return -j;
}

int insert(HashTable *hash, datatype x)
{
    int i =find(hash, x);
    if(i>=0) return 0;    //data x is exist
    else if(i != -hash->tablesize)
    {
        hash->ht[-i].data=x;
        hash->ht[-i].info=Active;
        hash->currentsize++;
        return 1;
    }    
    else return 0;
}

int delete(HashTable *hash, datatype x)
{
    int i=find(hash, x);
    if(i>=0)
    {
        hash->ht[i].info==delete;
        hash->currentsize--;
        return 1;
    }
    else return 0;
}

void destory(HashTable *hash)
{
    free(hash->ht);
}

