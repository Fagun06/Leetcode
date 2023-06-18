class Solution {
public:
#define ll long long
#define MOD 1000000007

int vis[1001][1001];
int n,m;
int ch[1001][1001];
int dp[1001][1001];

bool isvalid(ll x,ll y)
{
    if(x<0 || x>=n || y<0 || y>=m)return false;
    
    return true;
}
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
 

int dfs(ll x,ll y)
{
    ll crt=1;
    if(dp[x][y]!=-1) return dp[x][y];
    vis[x][y]=1;
    dp[x][y]=1;
    for(ll i=0;i<4;i++)
    {
        if(isvalid(x+dx[i],y+dy[i]) && ch[x+dx[i]][y+dy[i]] > ch[x][y])
        {
           crt+= dfs(x+dx[i],y+dy[i]);
            
        }
    }
    return dp[x][y]=crt%MOD;
}
    int countPaths(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) ch[i][j]=grid[i][j];
        }
        ll crt=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) crt+=dfs(i,j),crt%=MOD;
        }
        return crt;
    }
};
