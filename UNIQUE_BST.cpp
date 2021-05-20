int Solution::numTrees(int n) {
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    dp[1]=1;
    if(n<=1)
    {
        return dp[n];
    }
    for(int i=2;i<=n;i++)
    {
        for(int k=1;k<=i;k++)
        {
            dp[i]=dp[i]+dp[k-1]*dp[i-k];
        }
    }
    return dp[n];
}
