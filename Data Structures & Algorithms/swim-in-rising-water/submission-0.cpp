class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        n=grid.size();
        visit.assign(n,vector<int>(n,false));
        return dfs(grid,0,0,0);
    }
private:
    int n=0;
    vector<vector<int>> visit;
    int dfs(vector<vector<int>>& grid,int r, int c, int t)
    {
        if(r<0||c<0||r>=n||c>=n||visit[r][c]) return INT_MAX;
        if(r==n-1&&c==n-1) return max(t,grid[r][c]);
        visit[r][c]=true;
        t=max(t,grid[r][c]);
        int res=min(min(dfs(grid,r+1,c,t),dfs(grid,r-1,c,t)),min(dfs(grid,r,c+1,t),dfs(grid,r,c-1,t)));
        visit[r][c]=false;
        return res;
    }
};
