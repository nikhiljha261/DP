class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int dp[9];
        
        dp[0]=1;
        dp[1]=10;
        if(n==0) return dp[0];
        
        if(n==1) return dp[1];
        
        int k=9;
        for(int i=2;i<=n;i++){
            dp[i]=((dp[i-1]-dp[i-2])*k)+dp[i-1];
            k=k-1;
        }
        return dp[n];
    }


};
