#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000]={0};
int knapsack[1000][1000]={0};
int n,M;
void printdp(vector<pair<int,pair<int,int>>>&wp)
{
    cout<<"\nKnapsack Table:\n";
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=M;j++)
        {
            cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<"Take or Not Table:\n";
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=M;j++)
        {
            cout<<knapsack[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<"\nItems Taken:\n";
    int j=M;
    for(int i=n;i>0;i--)
    {
            if(j>0 && knapsack[i][j]==1)
            {
                cout<<wp[i-1].second.second+1<<"st\n";
                j=j-wp[i-1].first;
            }
    }
}
int zeroone(vector<pair<int,pair<int,int>>>&wp)
{
    sort(wp.begin(),wp.end());
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(j>=wp[i-1].first)
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-wp[i-1].first]+wp[i-1].second.first);
                if(dp[i-1][j]<(dp[i-1][j-wp[i-1].first]+wp[i-1].second.first))
                {
                    knapsack[i][j]=1;
                }
                else
                {
                    knapsack[i][j]=0;
                }
            }
            else{
                dp[i][j]=dp[i-1][j];
                knapsack[i][j]=0;
            }
        }
    }
    printdp(wp);
    return dp[n][M];
}
int main()
{
    cout<<"Enter the total numebr of item:";
    cin>>n;
    cout<<"Enter the capacity of knapsack:";
    cin>>M;
    vector<pair<int,pair<int,int>>>wp(n);
    cout<<"Enter the weight:";
    for(int i=0;i<n;i++)
    {
        cin>>wp[i].first;
        wp[i].second.second=i;
    }
    cout<<"Enter the Profit:";
    for(int i=0;i<n;i++)
    {
        cin>>wp[i].second.first;
    }
    cout<<"\nMaximum profit:"<<zeroone(wp);
}