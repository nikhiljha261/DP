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
map<pair<int,int>,pair<int,int>> dp;
//first max value in left sub tree
//second min sum of non leaf node
pair<int,int> fun(int st,int en,vector<int>& v)
{
    if(st==en)
    {
        return {v[st],0};
    }
    if(dp.count({st,en}))
    {
        return dp[{st,en}];
    }
    int minsum=INT_MAX;
    int maxleaf=INT_MIN;
    for(int i=st;i<en;i++)
    {
        auto left=fun(st,i,v);
        auto right=fun(i+1,en,v);
        maxleaf=max(left.first,right.first);
        minsum=min(minsum,left.second+right.second+left.first*right.first);
    }
    return dp[{st,en}]={maxleaf,minsum};
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
        int n;
        cin>>n;
        vector<int> v(n);
        loop(i,0,n)
        {
            cin>>v[i];
        }
        cout<<fun(0,n-1,v).second<<endl;
    }
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
}

