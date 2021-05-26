int Solution::longestValidParentheses(string s) {
    int n=s.length();
    bool dp[n+1][n+1];
    memset(dp,false,sizeof(dp));
    int ans=0;
    for(int i=0;i<n;i++)
    {
        dp[i][i]=false;
    }
    for(int i=0;i<n-1;i++)//for 2 length;
    {
        if(s[i]=='(' and s[i+1]==')')
        {
            dp[i][i+1]=true;
            ans=2;
        }
    }
    for(int i=3;i<=n;i++)
    {
        for(int j=0;j<n-i+1;j++)
        {
            int a=j;
            int b=j+i-1;
            if(s[a]=='(' and s[b]==')')
            {
                if(dp[a+1][b-1]==true)
                {
                    dp[a][b]=true;
                    ans=i;
                }
            }
        }
    }
    return ans;
    
} 
