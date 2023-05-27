#include<bits/stdc++.h>
using namespace std;
#define inf 99999
int graph[100][100];

void print(int pre[],int s,int d)
{
    if(s==d)
    {   
        cout<<s<<"  ";
        return;
    }
    else if(d==-1) 
    {
        cout<<"NO PATH";
    }
    else
    {
       print(pre,s,pre[d]);
       cout<<d<<"  ";
    }
}

int extract_min(int dis[],int visit[],int n)
{
    int min_vertex,distance=inf;
    for(int i=0;i<n;i++)
    {
        if(visit[i]==0 && dis[i]<distance)
        {
            min_vertex=i;
            distance=dis[i];
        }
    }
    return min_vertex;
}
void dijkshtra_algo(int n,int s)
{
    int dis[n],pre[n],visit[n];
    for(int i=0;i<n;i++)
    {
        dis[i]=inf;
        visit[i]=0;
        pre[i]=-1;
    }
    dis[s]=0;
    for(int i=0;i<n-1;i++)
    {
        int u=extract_min(dis,visit,n);
        visit[u]=1;
        for(int v=0;v<n;v++)
        {
             if(graph[u][v]&&visit[v]==0&&dis[u]+graph[u][v]<dis[v])
             {
                dis[v]=dis[i]+graph[u][v];
                pre[v]=u;
             }
        }
    }
    cout<<"DISTANCE ARRAY: ";
    for(int i=0;i<n;i++)
    {
       cout<<dis[i]<<"  ";
    }
    cout<<"\nPREDESESSOR ARRAY: ";
    for(int i=0;i<n;i++)
    {
       cout<<pre[i]<<"  ";
    }
    cout<<"\n";
    for(int i=0;i<n;i++)
    {
        if(i!=s)
        {
           cout<<"\nPATH "<<s<<" - "<<i<<": "; 
           print(pre,s,i);
        }
    }
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
   dijkshtra_algo(n,s);
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
DISTANCE ARRAY: 0  1  2  4
PREDESESSOR ARRAY: -1  0  0  1

PATH 0 - 1: 0  1
PATH 0 - 2: 0  2
PATH 0 - 3: 0  1  3
////////
Enter the number of vertices:4
Enter the adjecency matrix:
0 1 2 0
1 0 3 3
2 3 0 4
0 3 4 0
Enter the source vertex:1
DISTANCE ARRAY: 1  0  3  3
PREDESESSOR ARRAY: 1  -1  1  1

PATH 1 - 0: 1  0
PATH 1 - 2: 1  2
PATH 1 - 3: 1  3
*/