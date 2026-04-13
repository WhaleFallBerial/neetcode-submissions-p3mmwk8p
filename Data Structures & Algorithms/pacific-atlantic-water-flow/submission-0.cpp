class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows=heights.size();cols=heights[0].size();
        pac.assign(rows,vector<bool>(cols,false));
        atl.assign(rows,vector<bool>(cols,false));
        for(int c=0;c<cols;c++)
        {
            dfs(0,c,pac,heights);
            dfs(rows-1,c,atl,heights);
        }
        for(int r=0;r<rows;r++)
        {
            dfs(r,0,pac,heights);
            dfs(r,cols-1,atl,heights);
        }
        vector<vector<int>> res;
        for(int r=0;r<rows;r++)
        {
            for(int c=0;c<cols;c++)
            {
                if(pac[r][c]&&atl[r][c])
                {
                    res.push_back({r,c});
                }
            }
        }
        return res;
    }
private:
    int rows,cols;
    vector<vector<bool>> pac;
    vector<vector<bool>> atl;
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int r, int c, vector<vector<bool>>& ocean, vector<vector<int>>& heights)
    {
        ocean[r][c]=true;
        for(int i=0;i<4;i++)
        {
            int dr=r+dir[i][0],dc=c+dir[i][1];
        if(dr>=0&&dc>=0&&dr<rows&&dc<cols&&heights[dr][dc]>=heights[r][c]&&!ocean[dr][dc])
        {
            dfs(dr,dc,ocean,heights);
        }
        }
    }
};
