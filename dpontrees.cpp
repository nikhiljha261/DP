//har har mahadev
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(i,a,b)     for(int i=(a);i<(b);i++)
#define endl            "\n"
// cout<<fixed<<setprecision(9)<<" ";
// double rounded = std::floor((V * 100) + .5) / 100;

void ganeshji(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int n,m;
vector<int> a[100005];
int d[100005];

void dfs(int node)
{
    d[node]=max(d[node],0);
    for(auto child : a[node])
    {
        if(d[child]==-1)
        {
            dfs(child);
        }
        d[node]=max({d[node],1+d[child],0});
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
        cin>>n>>m;
        loop(i,0,m)
        {
            int x,y;
            cin>>x>>y;
            a[x].push_back(y);
        }
        memset(d,-1,sizeof(d));
        loop(i,1,n+1)
        {
            if(d[i]==-1)
            {
                dfs(i);
                d[i]=max(d[i],0);
            }
        }
        int maxi=INT_MIN;
        loop(i,1,n+1)
        {
            maxi=max(d[i],maxi);
        }
        cout<<maxi;

        
    }
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
}

