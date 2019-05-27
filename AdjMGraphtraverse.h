typedef struct 
{
    SeqList Vertices;
    int edge[MaxVertices]
    int numofEdges;
}AdjMGraph;

void DepthFSearch(AdjMGraph G, int v, int visited[], void Visit(datatype item))
{
    int w; 
    Visit(G.Vertices.list[v]);     //visit 'v'
    visited[v]=1;                  //give the tag 
    w=GetFirstVex(G,v);            //get the vex
    while(w!=1)
    {
        if(! visited[w])
        DepthFSearch(G, w, visited, Visit);
        w=GetNextVex(G, v ,w);
    }
}

void BroadFSearch(AdjMGraph G, int v, int visited[], void Visit(datatype item))
{
    int u,w;
    SeqCQueue queue;
    Visit(G.Verticeslist[v]);
    visited[v]=1;
    Queueinitiate(&queue);
    QueueAppend(&queue, v);
    while(QueueNotEmpty(queue))
    {
        QueueDelete(&queue, &u);
        w=GetFirstVex(G,u);
        while(w!=-1)
        {
            if(!visited[w])
            {
                visited(G.Vertices.list[w]);
                visited[w]=1;
                QueueAppend(&queue, w);
            }
            w=GetNextVex;
        }
    }
}