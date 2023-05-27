#include<iostream>
using namespace std;
float M;
void print(float arr[],int n)
{   
    cout<<"\nSolution vector: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";
}
void selection_sort(float ratio[],int x[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        float max=ratio[i];
        int index=i;
        for(int j=i+1;j<n;j++)
        {
           if(max<ratio[j])
           {
            max=ratio[j];
            index=j;
           }
        }
        float temp1=ratio[i];
        ratio[i]=ratio[index];
        ratio[index]=temp1;

        int temp2=x[i];
        x[i]=x[index];
        x[index]=temp2;
    }  
}
void knapsack(float w[],float p[],int n)
{
    float sol[n]={0},total=0;
    int x[n];
    float ratio[n];
    for(int i=0;i<n;i++)
    {
        ratio[i]=p[i]/w[i];
        x[i]=i;
    }
    selection_sort(ratio,x,n);
    for(int i=0;i<n;i++)
    {
        if(M-w[x[i]]>0)
        {
           total+=p[x[i]];
           M-=w[x[i]];
           sol[x[i]]=1;
        }
        else{
           total+=p[x[i]]*(M/w[x[i]]);
           sol[x[i]]=M/w[x[i]];
           break;
        }
    }
    print(sol,n);
    cout<<"Total Profit: "<<total<<endl;
}
int main()
{
    int n;
    cout<<"Enter weight of knapsack:";
    cin>>M;
    cout<<"Enter the no. of elements:";
    cin>>n;
    float w[n],p[n];
    cout<<"Enter the weights:";
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
    }
    cout<<"Enter the profits:";
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    knapsack(w,p,n);
    return 0;
}
/*
OUTPUT:
Enter weight of knapsack:60
Enter the no. of elements:4
Enter the weights:40 10 20 24
Enter the profits:280 100 120 120

Solution vector: 1      1       0.5     0
Total Profit: 440
*/