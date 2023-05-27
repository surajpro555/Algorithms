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
void selection_sort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min=a[i],index=i,flag=0;
        for(int j=i+1;j<n;j++)
        {
           if(min>a[j])
           {
            min=a[j];
            index=j;
            flag=1;
           }
        }
        int temp=a[i];
        a[i]=a[index];
        a[index]=temp;
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
    cout<<"\nAfter Selection Sort:\t";
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
    selection_sort(a,n);
    return 0;
}
/*
OUTPUT:
Enter the number of element:8
Enter the elements:1 5 3 4 67 4 56 3
Pass 1: No Change
Pass 2: 1       3       5       4       67      4       56      3
Pass 3: 1       3       3       4       67      4       56      5
Pass 4: No Change
Pass 5: 1       3       3       4       4       67      56      5
Pass 6: 1       3       3       4       4       5       56      67
Pass 7: No Change

After Selection Sort:   1       3       3       4       4       5       56      67
*/