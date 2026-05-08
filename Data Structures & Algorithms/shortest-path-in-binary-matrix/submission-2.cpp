class Solution {
    vector<vector<int>> dv={{-1,-1},{-1,0},{0,-1},{1,0},{0,1},{1,1},{-1,1},{1,-1}};

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1||grid[n-1][n-1]==1) return -1;
        deque<pair<int, int>> dq;
        vector<vector<bool>> v(n, vector<bool>(n, false));
        dq.push_back({0,0});
        int res=0;
        while(!dq.empty())
        {
            
            
            int level=dq.size();
            
            for(int i=0;i<level;i++)
            {
                auto [r, c] = dq.front();
                dq.pop_front();
                v[r][c]=true;
                if(r==n-1&&c==n-1)
            {
                return res+1;
            }
                for(auto d:dv)
                {
                    int nr=r+d[0];
                    int nc=c+d[1];
                    if(nr<0||nc<0||nr>=n||nc>=n||grid[nr][nc]==1||v[nr][nc])
                    {
                        continue;
                    }
                    dq.push_back({nr, nc});
                }

            }
            res++;

        }

        return -1;

    }
};