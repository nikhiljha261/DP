class Solution {
public:
    int n;
    int m;
    int dx[4]={+1,-1,0,0};
    int dy[4]={0,0,+1,-1};
    int dp[205][205];
    int fun(int i,int j,vector<vector<int>>& grid)
    {
        int ans=1;
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        for(int k=0;k<4;k++)
        {
            int ni=i+dx[k];
            int nj=j+dy[k];
            if(ni>=0 and nj>=0 and ni<n and nj<m and  grid[ni][nj]>grid[i][j])
            {
                
                    ans=max(ans,1+fun(ni,nj,grid));
                
            }
        }
        return dp[i][j]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        memset(dp,-1,sizeof(dp));
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans=max(ans,fun(i,j,matrix));
            }
        }
        return ans;
    }
};
