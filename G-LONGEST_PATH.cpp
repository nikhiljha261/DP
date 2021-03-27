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
bool vis[100001];
vector<int> adj[100001];
int dp[100001];

void dfs(int node)
{
    vis[node]=true;
    // dp[node]=1;
    for(auto child : adj[node])
    {
        if(vis[child]==false)
        {
            dfs(child);  
        }
        dp[node]=max(dp[node],1+dp[child]);
    }
}

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
        int n,m;
        cin>>n>>m;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=m;i++)
        {
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
        }
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==false)
            {
                dfs(i);
            }
        }
        int ans=0;
        loop(i,1,n+1)
        {
            ans=max(ans,dp[i]);
        }
        cout<<ans<<endl;
    }
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
}

