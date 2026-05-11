class Solution {
    vector<vector<int>> dr={{-1,0}, {0,-1}, {1,0}, {0,1}};
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& v,int r, int c, int m, int n)
    {
        if(r>=m||r<0||c>=n||c<0)
        {
            return;
        }
        if(v[r][c])
        {
            return;
        }
        
        if(grid[r][c]==1)
        {
            v[r][c]=true;
            for(auto d:dr)
            {
                int nr=r+d[0];
                int nc=c+d[1];
                dfs(grid, v, nr, nc, m, n);
            }
        }
        return;

    } 
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int res=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> v(m, vector<bool>(n, false));
        for(int r=0;r<m;r++)
        {
            dfs(grid, v, r, 0, m, n);
            dfs(grid, v, r, n-1, m, n);
        }

        for(int c=1;c<n-1;c++)
        {
            dfs(grid, v, 0, c, m, n);
            dfs(grid, v, m-1, c, m, n);
        }

        for(int r=0;r<m;r++)
        {
            for(int c=0;c<n;c++)
            {
                if(grid[r][c]==1&& !v[r][c])
                {
                    res++;
                }
            }
        }
        return res;
    }
};