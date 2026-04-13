class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int maxres=0;
        for(int r=0;r<rows;r++)
        {
            for(int c=0;c<cols;c++)
            {
                int land=0;
                dfs(grid,r,c,land,rows,cols,maxres);
            }
        }
        return maxres;
    }
private:
    int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(vector<vector<int>>& grid, int r, int c, int& land, int rows, int cols, int& maxres)
    {
        
    if(r<0||c<0||r>=rows||c>=cols||grid[r][c]==0){
        return;
    }
    grid[r][c]=0;
    land=land+1;
    maxres=max(land,maxres);
    for(int i=0;i<sizeof(d)/sizeof(d[0]);i++)
    {
        dfs(grid,r+d[i][0],c+d[i][1],land,rows,cols,maxres);
    }
    }
};
