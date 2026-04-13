class Solution {
public:
    int maxProfit(vector<int>& prices) {
        dp.assign(prices.size(),vector<int>(2,-1));
        return dfs(prices,0,false);
    }
private:
    vector<vector<int>> dp;
    int dfs(vector<int>& prices,int i, int bought)
    {
        if(i>=prices.size()) return 0;
        if(dp[i][bought]!=-1) return dp[i][bought];
        int res=dfs(prices,i+1, bought);
        if(bought)
        {
            res=max(res,prices[i]+dfs(prices,i+1,false));
        }else{
            res=max(res,-prices[i]+dfs(prices,i+1,true));
        }
        dp[i][bought]=res;
        return res;
    }
};