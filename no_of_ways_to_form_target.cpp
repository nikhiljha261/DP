// https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/
class Solution {
public:
    int way(int i,int j,string& target,vector<vector<int>>& v)
    {
        if(i==target.size())
        {
            return 1;
        }
        if(j>=v.size())
        {
            return 0;
        }
        int ans=0;
        ans+=way(i,j+1,target,v);
        ans+=v[j][target[i]-'a']*way(i+1,j+1,target,v);
        return ans;
    }
    int numWays(vector<string>& words, string target) {
        int n=words[0].size();
        vector<vector<int>> v(n,vector<int>(26,0));
        for(auto word : words)
        {
            for(int i=0;i<word.size();i++)
            {
                v[i][word[i]-'a']++;
            }
        }
        return way(0,0,target,v);
        
        
    }
};
