class Solution {
    int dfs(int r, int c, int m, int n, vector<vector<char>>& matrix, vector<vector<int>>& dp)
    {
        if(r<0||r>=m||c<0||c>=n)
        {
            return 0;
        }

        if(dp[r][c]!=-1)
        {
            return dp[r][c];
        }

        int right=dfs(r, c+1, m, n, matrix, dp);
        int down=dfs(r+1, c, m, n, matrix, dp);
        int diag=dfs(r+1, c+1, m, n, matrix, dp);
        if(matrix[r][c]=='0')
        {
            dp[r][c]=0;
        }else{
            dp[r][c]=1+min(right, min(down, diag));
        }

        return dp[r][c];

        
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        int res=0;
        dfs(0,0,m, n, matrix, dp);
        for(int r=0;r<m;r++)
        {
            for(int c=0;c<n;c++)
            {
                res=max(res,dp[r][c]);
            }
        }
        return res*res;
    }
};