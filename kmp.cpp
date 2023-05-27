#include<iostream>
using namespace std;
void lps_table(string p,int lps[])
{
     int i=1,k=0,n=p.size();
     lps[0]=0;
     while(i<n)
     {
       if(p[i]==p[k])
       {
         lps[i++]=++k;
       }
       else{
         if(k!=0)
         {
            k=lps[k-1];
         }
         else
         {
            lps[i]=0;
            i++; 
         }
       }
     } 
}
void kmp(string t,string p)
{
    int m=t.size(),n=p.size();
    int lps[n];
    lps_table(p,lps);
    int i=0,j=0;
    while(i<m)
    {
        if(t[i]==p[j])
        {
            i++;
            j++;
        }
        if(j==n)
        {
            cout<<"String match found at index:"<<i-j<<"\n";
            j=lps[j-1];
        }
        else if(i<m and t[i]!=p[j])
        {
            if(j!=0)
               j=lps[j-1];
            else
               i++;   
        }
    }
}
int main()
{
    string t,p;
    cout<<"Enter the text string:";
    cin>>t;
    cout<<"Enter the patern string:";
    cin>>p;
    kmp(t,p);
}
/*
Enter the text string:abbcbbsbcbbabb
Enter the patern string:abb
String match found at index:0
String match found at index:11
*/