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

void merge(int a[],int low,int mid,int high)
{
   int b[high-low+1],k=0,i=low,j=mid+1;
   while (i<=mid and j<=high)
   {
      if(a[i]<a[j])
         b[k++]=a[i++];
      else
         b[k++]=a[j++];
   }
   while(i<=mid)
      b[k++]=a[i++];
   while(j<=high)
      b[k++]=a[j++];  
   for(int i=low;i<=high;i++)
      a[i]=b[i-low]; 
}

void msort(int a[],int low,int high)
{
    counter++;
   if(low<high)
   {
      int mid=(low+high)/2;
      msort(a,low,mid);
      msort(a,mid+1,high);
      merge(a,low,mid,high);
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
    msort(a,0,n-1);
    cout<<"After Merge Sort:\t";
    print(a,n);
    cout<<"\nTotal number of call to quick processure:"<<counter;
    return 0;
}
/*
OUTPUT:
Enter the number of element:6
Enter the elements:1 5 3 2 6 4
After Merge Sort:       1       2       3       4       5       6

Total number of call to quick processure:11
*/