#include<iostream>
#include<algorithm>
using namespace std;
int counter=0;
void print(int arr[],int n)
{   
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";
}

int partition(int a[],int low,int high)
{
   int pi=low;
   for(int i=low;i<high;i++)
   {
      if(a[i]<a[high])
      {
         swap(a[pi],a[i]);
         pi++;
      }
   }
   swap(a[pi],a[high]);
   return pi;
}

void qsort(int a[],int low,int high)
{
    counter++;
   if(low<high)
   {
      int pi=partition(a,low,high);
      qsort(a,low,pi-1);
      qsort(a,pi+1,high);
   }
}

int main()
{
    int n;
    cout<<"Enter the number of element:";
    cin>>n;
    int a[n];
    cout<<"Enter the elements:";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    qsort(a,0,n-1);
    cout<<"After Quick Sort:\t";
    print(a,n);
    cout<<"\nTotal number of call to quick processure:"<<counter;
    return 0;
}
/*
OUTPUT:
Enter the number of element:6
Enter the elements:5 4 6 1 3 2
After Quick Sort:       1       2       3       4       5       6

Total number of call to quick processure:7
*/