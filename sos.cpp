#include<iostream>
using namespace std;
int x[1000],count=0,n;
void print(int w[],int k)
{
   cout<<"\nPossible Combination:\n";
   for(int i=0;i<n;i++)
   {
      if(i<=k)
      cout<<x[i]<<" ";
      else
      cout<<"0 ";
   }
   cout<<"\tWEIGHT-->{ ";
   for(int i=0;i<n;i++)
   {
      if(x[i] and i<=k)
      cout<<w[i]<<", ";
   }
   cout<<"}\n";
}
void sos(int k,int sum,int w[],int rem,int target)
{
   x[k]=1;
   count++;
   if(w[k]+sum==target)
   {
       print(w,k);
   }
   else if(sum+w[k]+w[k+1]<=target)
   {
     sos(k+1,sum+w[k],w,rem-w[k],target);
   }
   if(sum+rem-w[k]>=target and sum+w[k+1]<=target)
   {  x[k]=0;
      sos(k+1,sum,w,rem-w[k],target);    
   }
}
int main()
{
    cout<<"Enter the number element:";
    cin>>n;
    int w[n],total=0,target;
    cout<<"Enter the weights:";
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
        total+=w[i];
    }
    cout<<"Enter the target sum:";
    cin>>target;
    sos(0,0,w,total,target);
    cout<<"\nTotal number of call to proccesure:"<<count;
}
/*
Enter the number element:5
Enter the weights:5 7 8 12 13
Enter the target sum:20

Possible Combination:
1 1 1 0 0       WEIGHT-->{ 5, 7, 8, }

Possible Combination:
0 1 0 0 1       WEIGHT-->{ 7, 13, }

Possible Combination:
0 0 1 1 0       WEIGHT-->{ 8, 12, }

Total number of call to proccesure:12
*/