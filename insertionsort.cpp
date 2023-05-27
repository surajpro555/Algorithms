#include<iostream>
using namespace std;
int count=0;
void print(int arr[],int n)
{   
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";
}
void insertion_sort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int j=i,temp=a[i],flag=0;
        while(j>0 and temp<a[j-1])
        {
            a[j]=a[j-1];
            j--;
            flag=1;
        }
        a[j]=temp;
        count++;
        if(flag)
        { 
            cout<<"Pass "<<count<<":\t";
            print(a,n);
        }
        else 
        {
            cout<<"Pass "<<count<<": No Change\n";
        }
    }
    cout<<"\nAfter Insertion Sort:\t";
    print(a,n);
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
    insertion_sort(a,n);
    return 0;
}
/*
OUTPUT:
Enter the number of element:6
Enter the elements:1 4 7 2 5 3
Pass 1: No Change
Pass 2: No Change
Pass 3: 1       2       4       7       5       3
Pass 4: 1       2       4       5       7       3
Pass 5: 1       2       3       4       5       7

After Insertion Sort:   1       2       3       4       5       7
*/