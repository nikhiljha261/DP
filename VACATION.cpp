
#include <bits/stdc++.h>
using namespace std;

///////////////////////////////////////////////////


#define ll long long 


int n;
int a[100001][3];
int dp[100001][3];

int fun(int day,int ind)
{
    if(day==n+1)
    {
        return 0;
    }
    if(dp[day][ind]!=-1)
    {
        return dp[day][ind];
    }
    int ans=0;
    for(int i=0;i<3;i++)
    {
        if(i!=ind)
        {
            ans=max(ans,a[day][i]+fun(day+1,i));
        }
    }
    return dp[day][ind]=ans;
}



int main()
{
    
    // om_shree_ganeshaya_namah();
    ll tc;
    // cin>>tc;
    tc=1;
    while(tc--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=2;j++)
            {
                cin>>a[i][j];
            }
        }
        memset(dp,-1,sizeof(dp));
        cout<<fun(1,-1);
        
        
    }
    
}
