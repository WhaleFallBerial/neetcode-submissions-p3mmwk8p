class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int island=0;
        for(int r=0;r<row;r++)
        {
            for(int c=0;c<col;c++)
            {
                if(grid[r][c]=='1')
                {
                    dfs(grid,r,c,row,col);
                    island++;
                }
            }
        }
        return island;
    }
private:
    int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(vector<vector<char>>& grid,int r, int c, const int& row, const int& col)
    {
        if(r>=row||c>=col||r<0||c<0||grid[r][c]=='0') return;

        grid[r][c]='0';
        for(int i=0;i<4;i++)
        {
            dfs(grid,r+d[i][0],c+d[i][1],row,col);
        }        
    }
};
