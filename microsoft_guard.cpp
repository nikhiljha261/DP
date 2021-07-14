//har har mahadev
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(i,a,b)     for(int i=(a);i<(b);i++)
#define endl            "\n"

void ganeshji(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
int dx[4]={0,0,-1,+1};
int dy[4]={+1,-1,0,0};
int main()
{
    ganeshji();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    // cin>>t;
    while(t--)
    {
        
       int n,m;
       cin>>n>>m;
       vector<vector<char>> grid(n,vector<char>(m));
       loop(i,0,n)
       {
         loop(j,0,m)
         {
            cin>>grid[i][j];
         }
       }
       int x,y;
       loop(i,0,n)
       {
            loop(j,0,m)
            {
                if(grid[i][j]=='A')
                {
                    x=i;
                    y=j;
                    continue;
                }
                if(grid[i][j]=='<')//left
                {
                    grid[i][j]='X';
                    for(int k=j-1;k>=0;k--)
                    {
                        if(grid[i][k]=='.')
                        {
                            grid[i][k]='X';
                        }
                        else
                        {
                            break;
                        }
                    }
                    continue;
                }
                if(grid[i][j]=='>')//right
                {
                    grid[i][j]='X';
                    for(int k=j+1;k<m;k++)
                    {
                        if(grid[i][k]=='.')
                        {
                            grid[i][k]='X';
                        }
                        else
                        {
                            break;
                        }
                    }
                    continue;
                }
                if(grid[i][j]=='^')//up
                {
                    grid[i][j]='X';
                    for(int k=i-1;k>=0;k--)
                    {
                        if(grid[k][j]=='.')
                        {
                            grid[k][j]='X';
                        }
                        else
                        {
                            break;
                        }
                    }
                    continue;
                }
                if(grid[i][j]=='v')//down
                {
                    grid[i][j]='X';
                    for(int k=i+1;k<n;k++)
                    {
                        if(grid[k][j]=='.')
                        {
                            grid[k][j]='X';
                        }
                        else
                        {
                            break;
                        }
                    }
                    continue;
                }
            }
       }
       bool found=false;
       vector<vector<int>> vis(n,vector<int>(m,-1));
       queue<pair<int,int>> q;
       q.push({x,y});
       vis[x][y]=1;
       while(!q.empty())
       {
            int nx=q.front().first;
            int ny=q.front().second;
            q.pop();
            if(nx==n-1 and ny==m-1)
            {
                found=true;
                break;
            }
            loop(h,0,4)
            {
                int nxx=nx+dx[h];
                int nyy=ny+dy[h];
                if(nxx>=0 and nxx<n and nyy>=0 and nyy<m and vis[nxx][nyy]==-1 and grid[nxx][nyy]!='X')
                {
                    vis[nxx][nyy]=1;
                    q.push({nxx,nyy});

                }
            }
       }
       if(found==true) cout<<"True"<<endl;
       else cout<<"False";
    }
} 
