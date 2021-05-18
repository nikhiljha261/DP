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
        int red[n];
        int blu[n];
        int green[n];
        loop(i,0,n)
        {
            cin>>red[i];
        }
        loop(i,0,n)
        {
            cin>>blu[i];
        }
        loop(i,0,n)
        {
            cin>>green[i];
        }
        int pg=green[0];
        int pb=blu[0];
        int pr=red[0];
        for(int i=2;i<=n;i++)
        {
            int op1=red[i-1]+min(pg,pb);
            int op2=blu[i-1]+min(pr,pg);
            int op3=green[i-1]+min(pr,pb);
            // dp[i]=min(op1,op2,op3);
            pg=op3;
            pr=op1;
            pb=op2;
        }
        cout<<min({pg,pb,pr});
    }
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
}  
