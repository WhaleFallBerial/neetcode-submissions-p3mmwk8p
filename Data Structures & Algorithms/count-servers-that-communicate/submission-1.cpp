class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int nr=grid.size();
        int nc=grid[0].size();
        vector<vector<int>> dp(nr, vector<int>(nc,0));
        int res=0;
        vector<int> fr(nr,0);
        vector<int> fc(nc,0);
        
        for(int r=0;r<nr;r++)
        {
            for(int c=0;c<nc;c++)
            {
                if(grid[r][c]==1)
                {
                    fr[r]++;
                    fc[c]++;
                }
                
            }
        }

        for(int r=0;r<nr;r++)
        {
            for(int c=0;c<nc;c++)
            {
                if(grid[r][c]==1&& (fr[r]>1||fc[c]>1))
                {
                   res++;
                }
                
            }
        }
        return res;
    }
};