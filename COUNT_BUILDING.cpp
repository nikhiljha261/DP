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
int dp[1005][2][2];
int countway(int ind,int n,vector<vector<bool>> v)
{
    if(ind==n-1)
    {
        if(v[0][ind]==true)
        {
            if(v[1][ind]==true)
            {
                return 4;
            }
            else
            {
                return 2;
            }
        }
        else
        {
            if(v[1][ind]==true)
            {
                return 2;
            }
            else
            {
                return 1;
            }
        }
    }
    int one=0;
    int two=0;
    if(v[0][ind]==true)
    {
        one=1;
    }
    if(v[1][ind]==true)
    {
        two=1;
    }
    if(dp[ind][one][two]!=-1)
    {
        return dp[ind][one][two];
    }
    int ans=0;
    if(v[0][ind]==true)
    {
        if(v[1][ind]==true)
        {
            // int ans=0;
            v[0][ind+1]=false;
            ans=ans+countway(ind+1,n,v);
            v[1][ind+1]=false;
            ans=ans+countway(ind+1,n,v);
            v[0][ind+1]=true;
            ans=ans+countway(ind+1,n,v);
            v[1][ind+1]=true;
            ans=ans+countway(ind+1,n,v);
        }
        else
        {
            v[0][ind+1]=false;
            ans=ans+countway(ind+1,n,v);
            v[0][ind+1]=true;
            ans=ans+countway(ind+1,n,v);
        }
    }
    else
    {
        if(v[1][ind]==false)
        {
            ans=ans+countway(ind+1,n,v);
        }
        else
        {
            v[1][ind+1]=false;
            ans=ans+countway(ind+1,n,v);
            v[1][ind+1]=true;
            ans=ans+countway(ind+1,n,v);
        }
    }
    return dp[ind][one][two]=ans;
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
        memset(dp,-1,sizeof(dp));
        int n;
        cin>>n;
        vector<vector<bool>> v(2,vector<bool>(n,true));
        cout<<countway(0,n,v);
    }
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
}

