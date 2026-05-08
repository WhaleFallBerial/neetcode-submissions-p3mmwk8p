class Solution {
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int r, int c, int n)
    {
        if(r>=n||c>=n||r<0||c<0||visited[r][c]==1||grid[r][c]==0) return;

        if(grid[r][c]==1)
        {
            visited[r][c]=1;
        }
        dfs(grid, visited, r-1, c, n);
        dfs(grid, visited, r, c-1, n);
        dfs(grid, visited, r+1, c, n);
        dfs(grid, visited, r, c+1, n);
        return;
    }
    void bfs(vector<vector<int>>&grid, vector<vector<int>>&visited, deque<pair<int, int>>& dq, int &res, int n)
    {
        while(!dq.empty())
        {
            
            int ndq=dq.size();
            int dirs[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
            for(int i=0; i<ndq; i++)
            {
            auto [curr, curc]=dq.front();
            dq.pop_front();
            for (auto& d : dirs) {
                    int nr = curr + d[0], nc = curc + d[1];
                    if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
                    if (visited[nr][nc] == 1) continue;  // 已訪問（第一島或已擴張的水）
                    
                    if (grid[nr][nc] == 1) {
                        return;
                    }
                    // 是水（grid == 0）
                    visited[nr][nc] = 1;
                    dq.push_back({nr, nc});
                }
            }
            res++;        
        }

        return;
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int res=0;
        int n=grid.size();
        vector<vector<int>> visited(n, vector<int>(n,0));
        bool found=false;
        for(int r=0;r<n;r++)
        {
            if(found) break;
            for(int c=0;c<n;c++)
            {
                if(grid[r][c]==1)
                {
                    dfs(grid, visited, r, c, n);
                    found=true;
                    break;
                }
            }
        }
        deque<pair<int, int>> dq;
        
        for(int r=0;r<n;r++)
        {
            for(int c=0;c<n;c++)
            {
                if(visited[r][c]==1)
                    dq.push_back({r, c});
            }
        }
        bfs(grid, visited, dq,res, n);
        return res;

    }
};