class Solution {
    long long dfs(vector<vector<int>>& points, vector<vector<long long>>& dp, int m, int n, int r, int c)
    {
        if(r>=m||c>=n||r<0||c<0)
        {
            return (long long)0;
        }
        if(dp[r][c]!=-1)
        {
            return dp[r][c];
        }
        long long tmp=INT_MIN;
        for(int i=0;i<n;i++)
        {
            tmp=max(tmp, dfs(points, dp, m, n, r+1, i)-abs(i-c));
        }
        dp[r][c]=points[r][c]+tmp;
        


        return dp[r][c];
    }
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m=points.size();
        int n=points[0].size();
        vector<vector<long long>>dp(m, vector<long long>(n,-1));
        long long res=(long long)INT_MIN;
        for(int i=0;i<n;i++)
        {
            res=max(res, dfs(points, dp, m, n, 0, i));
        }
        return res;
    }
};