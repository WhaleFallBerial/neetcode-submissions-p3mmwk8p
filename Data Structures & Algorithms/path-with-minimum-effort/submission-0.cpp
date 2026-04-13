class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int cols=heights[0].size();
        int rows=heights.size();
        
        vector<vector<int>> direction={{0,1},{0,-1},{1,0},{-1,0}};
        int l=0, r=1000000;
        int res=r;
        while(l<=r)
        {
            int mid=(l-r)/2+r;
            vector<vector<int>> dp(rows, vector<int>(cols, -1));
            if(dfs(0,0,mid,cols,rows,heights,dp,direction))
            {
                r=mid-1;
                res=mid;
            }else{
                l=mid+1;
            }

        }
        return res;



    }

    bool dfs(int c, int r,int limit, int cols, int rows, vector<vector<int>>& heights, vector<vector<int>>& dp,vector<vector<int>>& direction)
    {
        
        if(c==cols-1&&r==rows-1) return true;
        dp[r][c]=1;
        for(auto d:direction)
        {
            int newc=c+d[0];
            int newr=r+d[1];
            
            if(newc>=cols||newr>=rows||newc<0||newr<0) continue;
            if(dp[newr][newc]!=-1) continue;
            if(abs(heights[newr][newc]-heights[r][c])>limit) continue;
            if(dfs(newc,newr,limit,cols,rows,heights,dp,direction))
            {
                return true;
            }
            
        }
        return false;


    }
};