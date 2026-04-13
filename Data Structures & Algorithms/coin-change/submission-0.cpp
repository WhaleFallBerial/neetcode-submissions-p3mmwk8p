class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int res=dfs(coins,amount);
        return res==INT_MAX?-1:res;
    }
private:
    unordered_map<int,int> dp;
    int dfs(vector<int>& coins, int amount)
    {
        if(amount==0) return 0;
        if(dp.count(amount)) return dp[amount];
        
        int res=INT_MAX;
        for(auto& c:coins)
        {
            if(amount-c>=0)
            {
                int result=dfs(coins,amount-c);
                if(result!=INT_MAX) res=min(res,1+result);
            }
        }
        dp[amount]=res;
        return res;
    }
};

