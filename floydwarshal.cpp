#include<bits/stdc++.h>
using namespace std;
#define inf 9999
int d[100][100],pi[100][100],n;
void print()
{
       cout<<"\nDISTANCE MATRIX:\n";
       for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
              cout<<d[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\nPI MATRIX:\n";
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
              cout<<pi[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
}
void path(int s,int p)
{
   if(s==p) 
   {
      cout<<s<<"  ";
      return;
   }else if(p==-1)
   {
     cout<<"NO PATH to";
   }else{
      path(s,pi[s][p]);
      cout<<p<<"  ";
   }
}
void all_path()
{
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
               cout<<"\nPath between "<<i<<"-"<<j<<" : ";
               path(i,j);
            }
            cout<<"\n";
        }
}
void floydwarshal()
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(d[i][k]!=inf and d[k][j]!=inf and d[i][j]>d[i][k]+d[k][j])
                {
                    d[i][j]=d[i][k]+d[k][j];
                    pi[i][j]=pi[k][j];
                }
            }
        }
    }
    print();
    all_path();
}

int main()
{
   cout<<"Enter the number of vertices:";
   cin>>n;    
   cout<<"Enter the adjecency matrix(inf=9999):\n";
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
          cin>>d[i][j];
          if(i==j ||d[i][j]==9999)
          {
             pi[i][j]=-1;
          }else{
             pi[i][j]=i;
          }
       }
   }
   floydwarshal();
   return 0;
}
/*
Enter the number of vertices:3
Enter the adjecency matrix(inf=9999):
0 7 10
9999 0 3
4 9999 0

DISTANCE MATRIX:
0 7 10
7 0 3
4 11 0

PI MATRIX:
-1 0 0
2 -1 1
2 0 -1


Path between 0-0 : 0
Path between 0-1 : 0  1
Path between 0-2 : 0  2

Path between 1-0 : 1  2  0
Path between 1-1 : 1
Path between 1-2 : 1  2

Path between 2-0 : 2  0
Path between 2-1 : 2  0  1
Path between 2-2 : 2

Press any key to continue . . .
*/