//har har mahadev
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(i,a,b)     for(int i=(a);i<(b);i++)
#define endl            "\n"

void ganeshji(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

int n,m,sz;
bool il(string a,string b,string c,int i,int j,int k)
{
    if(i+j==n+m)
    {
        return true;
    }
    if(k==sz)
    {
        return false;
    }
    bool ans=false;
    if(i<n and a[i]==c[k])
    {
        ans=ans or il(a,b,c,i+1,j,k+1);
    }
    if(j<m and b[j]==c[k])
    {
        ans=ans or il(a,b,c,i,j+1,k+1);
    }
    ans=ans or il(a,b,c,i,j,k+1);
    return ans;
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
        string a,b,c;
        cin>>a>>b>>c;
        n=a.length();
        m=b.length();
        sz=c.length();
        if(n+m!=sz)
        {
            cout<<false;
        }
        cout<<il(a,b,c,0,0,0);
    }
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
}
