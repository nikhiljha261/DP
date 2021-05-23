 bool canReach(string s, int mini, int maxi) {
        queue<int> q;
        q.push(0);
        int mx=0;
        int n=s.length();
        while(!q.empty())
        {
            int top=q.front();
            q.pop();
            for(int i=max(top+mini,mx+1);i<=min(n-1,top+maxi);i++)
            {
                if(s[i]=='0')
                {
                    if(i==n-1) return true;
                    q.push(i);
                }
            }
            mx=top+maxi;
        }
        return false;
    }
