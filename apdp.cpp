class Solution {
public:
//     int dp[50005];
//     int dp[10][1<<10];
//     bool isvalid(vector<int>& v)
//     {
//         int c=1;
//         if(v.size()==1) return 1;
//         if(v.size()==0) return 0;
//         int d=v[1]-v[0];
        
//         for(int i=2;i<v.size();i++)
//         {
//             if(v[i]-v[i-1]!=d)
//             {
//                 return 0;
//             }
//         }
//         return v.size();
//     }
//     int fun(int ind,vector<int> v,vector<int>&nums,int mask)
//     {
//         if(ind==nums.size())
//         {
//             if(isvalid(v))
//             {
//                 return v.size();
//             }
//             return 0;
//         }
//         int ans=0;
//         if(dp[ind][mask]!=-1)
//         {
//             return dp[ind][mask];
//         }
//         v.push_back(nums[ind]);
//         mask=mask^(1<<ind);
//         ans=max(ans,fun(ind+1,v,nums,mask));
//         mask=mask^(1<<ind);
//         v.pop_back();
//         ans=max(ans,fun(ind+1,v,nums,mask));
//         return dp[ind][mask]=ans;
        
//     }
    int un(vector<int>& nums,int n)
    {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
        }
        int d=maxi-mini;
        int dp[n+1][d+1];
        for(int i=0;i<n;i++)
        {
            for(int k=0;k<=d;k++)
            {
                dp[i][k]=1;
            }
        }
        for(int i=0;i<n;i++)
        {
            
            for(int j=i-1;j>=0;j--)
            {
                if(nums[i]>=nums[j])
                {
                    int dif=nums[i]-nums[j];
                    dp[i][dif]=max(dp[i][dif],1+dp[j][dif]);
                    
                }
                
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int k=0;k<=d;k++)
            {
                ans=max(ans,dp[i][k]);
            }
        }
        return ans;
    }
    int nu(vector<int>& nums,int n)
    {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
        }
        int d=maxi-mini;
        int dp[n+1][d+1];
        for(int i=0;i<n;i++)
        {
            for(int k=0;k<=d;k++)
            {
                dp[i][k]=1;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                    
                    if(nums[j]>=nums[i])
                    {
                        int dif=abs(nums[i]-nums[j]);
                        dp[i][dif]=max(dp[i][dif],1+dp[j][dif]);
                    }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int k=0;k<=d;k++)
            {
                ans=max(ans,dp[i][k]);
            }
        }
        return ans;
    }
    int longestArithSeqLength(vector<int>& nums) {
        vector<int> v;
        int n=nums.size();
        // memset(dp,-1,sizeof(dp));
        // fun(0,v,nums,(1<<n)-1);
        int ans1=un(nums,n);
        int ans2=nu(nums,n);
        return max(ans1,ans2);
    }
};
