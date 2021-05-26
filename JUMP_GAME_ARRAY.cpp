int n;
int dp[1000005];
bool fun(int ind,vector<int>& a)
{
    if(ind==n-1)
    {
        return true;
    }
    if(ind>n)
    {
        return false;
    }
    int jump=a[ind];
    bool ans=false;
    if(jump==0) return false;
    if(dp[ind]!=-1)
    {
        if(dp[ind]==1) return true;
        else return false;
    }
    for(int i=1;i<=jump;i++)
    {
        if(i+ind<=n-1) ans=ans or fun(ind+i,a);
    }
    if(ans==true) dp[ind]=1;
    else dp[ind]=0;
    return ans;
}

int Solution::canJump(vector<int> &a) {
    memset(dp,-1,sizeof(dp));
    n=a.size();
    return fun(0,a);
    
    
} 
