// https://leetcode.com/problems/maximize-score-after-n-operations/submissions/
class Solution {
public:
    int n;
    int gcd(int a,int b)
    {
        if(b==0)
        {
            return a;
        }
        return gcd(b,a%b);
    }
    int dp[18][1<<16];
    int score(vector<int>& nums,int c,int mask)
    {
        if(2*c==n)
        {
            return 0;
        }
        if(dp[c][mask]!=-1)
        {
            return dp[c][mask];
        }
        int ans=INT_MIN;
        for(int i=0;i<n-1;i++)
        {
            if(mask&(1<<i))
            {
                for(int j=i+1;j<n;j++)
                {
                    if(mask&(1<<j))
                    {
                        int gc=(c+1)*gcd(nums[i],nums[j]);
                        mask=mask^(1<<j);
                        mask=mask^(1<<i);
                        ans=max(ans,gc+score(nums,c+1,mask));
                        mask=mask^(1<<j);
                        mask=mask^(1<<i);
                    }
                }
            }
        }
        return dp[c][mask]=ans;
        
    }
    int maxScore(vector<int>& nums) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return score(nums,0,(1<<n)-1);
        
    }
};
