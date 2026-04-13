class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows=obstacleGrid.size();
        int cols=obstacleGrid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        return dfs(0,0,rows,cols, obstacleGrid, dp);
    }

    int dfs(int r, int c, int rows, int cols, 
    vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp)
    {
        if(r>=rows||c>=cols) return 0;
        if(obstacleGrid[r][c]) return 0;
        if(r==rows-1&&c==cols-1) return 1;
        
        if(dp[r][c]!=-1) return dp[r][c];
        int res=0;
        res=dfs(r+1,c, rows, cols, obstacleGrid, dp)+dfs(r,c+1, rows, cols, obstacleGrid, dp);
        dp[r][c]=res;
        return res;
    }
};