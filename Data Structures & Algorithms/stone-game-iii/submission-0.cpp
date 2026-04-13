class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        int total=accumulate(stoneValue.begin(), stoneValue.end(),0);

        vector<int> dp(n+1,INT_MIN);
        int res=dfs(n, 0,stoneValue, dp);
        if(res==0) 
            return "Tie";
        else if(res>0)
            return "Alice";
        else
            return "Bob";
    }
    int dfs(int n, int i, vector<int>& stoneValue, vector<int>& dp)
    {
        if(i>=n) return 0;
        if(dp[i]!=INT_MIN) return dp[i];

        int res=INT_MIN;
        int total=0;

        for(int j=i;j<min(i+3,n);j++)
        {
            total+=stoneValue[j];
            res=max(res, total-dfs(n, j+1, stoneValue, dp));

        }
        dp[i]=res;
        return res;
    }
};