class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int cols=grid[0].size();
        int rows=grid.size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        return dfs(0,0, rows, cols,grid, dp);

    }

    int dfs(int r, int c, int rows, int cols, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        if(r>=rows||c>=cols) return INT_MAX;
        if((r==rows-1)&&(c==cols-1)) return grid[r][c];
        if(dp[r][c]!=-1) return dp[r][c];

        int res=grid[r][c]+min(dfs(r+1, c,rows, cols, grid, dp),dfs(r, c+1,rows, cols, grid, dp));
        dp[r][c]=res;
        return res;
    }
};