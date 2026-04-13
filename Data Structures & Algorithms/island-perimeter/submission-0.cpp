class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int res=0;
        for(int r=0;r<rows;r++)
        {
            for(int c=0;c<cols;c++)
            {
                if(grid[r][c])
                {
                    res+=4;
                    if(r&&grid[r-1][c])
                    {
                        res-=2;
                    }
                    if(c&&grid[r][c-1])
                    {
                        res-=2;
                    }
                }
            }
        }
        return res;
    }
};