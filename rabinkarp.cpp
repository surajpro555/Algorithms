#include<iostream>
using namespace std;
void rabin(string s,string pat)
{
    int m=s.size(),n=pat.size();
    int q=13,h=1,d=10;
    int t=0,p=0;
    for(int i=0;i<n-1;i++)
         h=(h*d)%q;
    for(int i=0;i<n;i++)
    {
         t=(t*d+(s[i]-'a'))%q;
         p=(p*d+(pat[i]-'a'))%q;
    }
    for(int i=0;i<=m-n;i++)
    {
        if(t==p)
        {
            int j;
            for(j=0;j<n;j++)
            {
                if(pat[j]!=s[i+j])
                    break;
            }
            if(j==n)
               cout<<"String match found at index:"<<i<<"\n";
        }
        if(i<m-n)
          t=(d*(t-(h*(s[i]-'a')))+(s[i+n]-'a'))%q;
        if(t<0)
          t=t+q;
    }
}
int main()
{
    string t,p;
    cout<<"Enter the text string:";
    cin>>t;
    cout<<"Enter the patern string:";
    cin>>p;
    rabin(t,p);
}
/*
Enter the text string:abbcbbsbcbbabb
Enter the patern string:abb
String match found at index:0
String match found at index:11
*/