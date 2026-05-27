class Solution {
    int dfs(vector<vector<int>>& grid, vector<vector<vector<vector<int>>>>& dp, int r1, int c1, int r2, int c2, int n)
    {
        if(r1>=n||c1>=n||r2>=n||c2>=n||grid[r1][c1]==-1||grid[r2][c2]==-1)
        {
            return INT_MIN;
        }
        if(r1==n-1&&c1==n-1&&r2==n-1&&c2==n-1)
        {
            return grid[n-1][n-1];
        }
        if(dp[r1][c1][r2][c2]!=-1) return dp[r1][c1][r2][c2];
        
        int res=dfs(grid, dp, r1+1, c1, r2+1, c2, n);
        res=max(res, dfs(grid, dp, r1, c1+1, r2, c2+1, n));
        res=max(res, dfs(grid, dp, r1+1, c1, r2, c2+1, n));
        res=max(res, dfs(grid, dp, r1, c1+1, r2+1, c2, n));
        res+=grid[r1][c1]+grid[r2][c2];
        if(r1==r2&&c1==c2) res-=grid[r1][c1];
        return dp[r1][c1][r2][c2]=res;
    }

   
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(n, vector<vector<int>>(n,vector<int>(n,-1) )));
        
        return max(0, dfs(grid, dp, 0,0,0,0,n));
    }
};