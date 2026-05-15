class Solution {
    double dfs(int n, int k, int maxPts, vector<double>& dp, int points)
    {
        if(points>n)
        {
            return 0.0;
        }
       
        if(points>=k)
        {
            return 1.0;
        }
        if(dp[points]!=-1.0) return dp[points];

        if(points<k)
        {
            double p=0.0;
            for(int i=1;i<=maxPts;i++)
            {
                p+=dfs(n, k, maxPts, dp, points+i);
            }
            dp[points]=p/maxPts;
        }
        return dp[points];
    }
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(n+1,-1.0);
        return dfs(n, k, maxPts, dp, 0);
    }
};