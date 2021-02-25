//har har mahadev
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(i,a,b)     for(int i=(a);i<(b);i++)
#define endl            "\n"
// cout<<fixed<<setprecision(9)<<" ";

void ganeshji(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int n;
int a[100001];
int k;
int dp[100001];

int main()
{
    ganeshji();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    clock_t begin = clock();
    ll t=1;
    // cin>>t;
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        cin>>n;
        cin>>k;
        loop(i,0,n)
        {
            cin>>a[i];
        }
        dp[0]=0;
        
        for(int ind=1;ind<n;ind++)
        {
            int ans=INT_MAX;
            for(int i=ind-1;i>=max(0,ind-k);i--)
            {
                ans=min(ans,dp[i]+abs(a[ind]-a[i]));
            }
            dp[ind]=ans;
        }  
    }
        cout<<dp[n-1];
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
}

