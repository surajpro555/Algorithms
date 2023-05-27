#include<iostream>
using namespace std;
int x[1000],count=0;
void print(int n)
{
   count++;
   cout<<"\nPossible Combination "<<count<<":\n";
   for(int i=0;i<n;i++)
   {
    //   for(int j=0;j<n;j++)
    //   {
    //       if(x[j]==i) 
    //         cout<<" Q ";
    //       else
    //         cout<<" . ";
    //   }
    //   cout<<"\n";
    cout<<x[i]<<"  ";
   }
   cout<<"\n";
}
bool isplace(int k,int i)
{
   for(int j=0;j<k;j++)
   {
       if(x[j]==i or abs(j-k)==abs(x[j]-i))
       {
          return false;
       }
   }
   return true;
}
void nqueen(int k,int n)
{
    for(int i=0;i<n;i++)
    {
        if(isplace(k,i))
        {
            x[k]=i;
            if(k==n-1)
             print(n);
            else
             nqueen(k+1,n); 
        }
    }
}
int main()
{
    int n;
    cout<<"Enter the queen no.:";
    cin>>n;
    nqueen(0,n);
}
/*
Enter the queen no.:4

Possible Combination 1:
 .  .  Q  .
 Q  .  .  .
 .  .  .  Q
 .  Q  .  .

Possible Combination 2:
 .  Q  .  .
 .  .  .  Q
 Q  .  .  .
 .  .  Q  .

*/