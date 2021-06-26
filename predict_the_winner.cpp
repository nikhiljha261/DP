class Solution {
public:
    int fun(int i,int j,vector<int>& nums,int bit)
    {
        if(i>j)
        {
            return 0;
        }
        // int ans=INT_MIN;
        int ans1=INT_MAX;
        if(bit==0)
        {
            int ans=INT_MIN;
            ans=max(ans,nums[i]+fun(i+1,j,nums,bit^1));
            ans=max(ans,nums[j]+fun(i,j-1,nums,bit^1));
            return ans;
        }
        else
        { 
            ans1=min(ans1,fun(i+1,j,nums,bit^1));
            ans1=min(ans1,fun(i,j-1,nums,bit^1));
        }
        return ans1;
    }
    bool PredictTheWinner(vector<int>& nums) {
        int s=0;
        for(int i=0;i<nums.size();i++)
        {
            s+=nums[i];
        }
        int p1=fun(0,nums.size()-1,nums,0);
        cout<<p1;
        int p2=s-p1;
        if(p1>=p2)
        {
            return true;
        }
        return false;
        
    }
};
