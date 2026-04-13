class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int INF = 2147483647;
        int rows=grid.size();
        int cols=grid[0].size();
        queue<pair<int, int>> q;
        for(int r=0;r<rows;r++)
        {
            for(int c=0;c<cols;c++)
            {
                if(grid[r][c]==0)
                {
                    q.push({r,c});
                }
            }
        }

        vector<vector<int>> dis={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty())
        {
            int qrow=q.front().first;
            int qcol=q.front().second;
            q.pop();

            for(int i=0;i<4;i++)
            {
                int r=qrow+dis[i][0];
                int c=qcol+dis[i][1];
                if(r<0||c<0||r>=rows||c>=cols||grid[r][c]!=INF)
                {
                    continue;
                }
                grid[r][c]=grid[qrow][qcol]+1;
                q.push({r,c});
            }
        }
        
    }
};
