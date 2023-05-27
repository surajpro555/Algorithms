#include<bits/stdc++.h>
using namespace std;
#define inf 99999
int graph[100][100];

int extract_min(int key[],int visit[],int n)
{
    int min_vertex,keytance=inf;
    for(int i=0;i<n;i++)
    {
        if(visit[i]==0 && key[i]<keytance)
        {
            min_vertex=i;
            keytance=key[i];
        }
    }
    return min_vertex;
}
void prim_algo(int n,int s)
{
    int key[n],pre[n],visit[n];
    for(int i=0;i<n;i++)
    {
        key[i]=inf;
        visit[i]=0;
        pre[i]=-1;
    }
    key[s]=0;
    for(int i=0;i<n-1;i++)
    {
        int u=extract_min(key,visit,n);
        visit[u]=1;
        for(int v=0;v<n;v++)
        {
             if(graph[u][v]&&visit[v]==0&&graph[u][v]<key[v])
             {
                key[v]=graph[u][v];
                pre[v]=u;
             }
        }
    }
    int cost=0;
    cout<<"\n---------------------\nEdges\tCost\n--------------------\n";
    for(int i=0;i<n;i++)
    {
        if(i!=s)
        {
           cout<<pre[i]<<" - "<<i<<"\t"<<graph[pre[i]][i]<<"\n";
           cost+=graph[pre[i]][i];
        }
    }
    cout<<"MINIMUM COST SPANING TREE:"<<cost;
}

int main()
{
   int n,s;
   cout<<"Enter the number of vertices:";
   cin>>n;    
   cout<<"Enter the adjecency matrix:\n";
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
          cin>>graph[i][j];
       }
   }
   cout<<"Enter the source vertex:";
   cin>>s;
   prim_algo(n,s);
   return 0;
}
/*
Enter the number of vertices:4
Enter the adjecency matrix:
0 1 2 0
1 0 3 3
2 3 0 4
0 3 4 0
Enter the source vertex:0

---------------------
Edges   Cost
--------------------
0 - 1   1
0 - 2   2
1 - 3   3
MINIMUM COST SPANING TREE:6
*/