#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
string back[1000][1000];
void print_LCS(string s1,int m,int n)
{
   if(m==0||n==0)
    return;
   else if(back[m][n]=="d")
   {
      print_LCS(s1,m-1,n-1);
      cout<<s1[m-1];
   }
   else if(back[m][n]=="u")
     print_LCS(s1,m-1,n);
   else
     print_LCS(s1,m,n-1);  
}
void lcs(string s1,string s2)
{
    int m=s1.size(),n=s2.size();
    for(int i=0;i<=n;i++)  
        dp[0][i]=0;
    for(int i=0;i<=m;i++)  
        dp[i][0]=0; 
    for(int i=1;i<=m;i++) 
    {
        for(int j=1;j<=n;j++)
        {
           if(s1[i-1]==s2[j-1])
           {
                dp[i][j]=dp[i-1][j-1]+1;
                back[i][j]="d";
           }
           else if(dp[i-1][j]>=dp[i][j-1])
           {
               dp[i][j]=dp[i-1][j];
               back[i][j]="u";
           }
           else{
               dp[i][j]=dp[i][j-1];
               back[i][j]="l";
           }
        }
    }
   cout<<"Length of LCS:"<<dp[m][n]<<"\n";
   cout<<"Longest common subsequnces:";
   print_LCS(s1,m,n);
}
int main()
{
    string s1,s2;
    cout<<"Enter the string1:";
    cin>>s1;
    cout<<"Enter the string2:";
    cin>>s2;
    lcs(s1,s2);
}
/*
Enter the string1:ABCDENS
Enter the string2:BDSNEA
Length of LCS:3
Longest common subsequnces:BDE
*/