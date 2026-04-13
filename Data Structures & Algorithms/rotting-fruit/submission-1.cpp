class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh=0;
        int time=0;
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<int>> d={{1,0},{-1,0},{0,1},{0,-1}};
        for(int r=0;r<rows;r++)
        {
            for(int c=0;c<cols;c++)
            {
                if(grid[r][c]==1)
                {
                    fresh++;
                }else if(grid[r][c]==2)
                {
                    q.push({r,c});
                }
            }
        }
        while(fresh&&!q.empty())
        {
            int len=q.size();
            for(auto j=0;j<len;j++)
            {
            int qr=q.front().first;
            int qc=q.front().second;
            q.pop();

            for(int i=0;i<4;i++)
            {
                int r=qr+d[i][0];
                int c=qc+d[i][1];
                if(r>=0&&c>=0&&r<rows&&c<cols&&grid[r][c]==1)
                {
                    grid[r][c]=2;
                    q.push({r,c});
                    fresh--;
                }
            }
            }
        time++;
        }
        return !fresh?time:-1;
    }
};
