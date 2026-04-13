class Solution {
public:
    int maxProfit(vector<int>& prices) {
        mem.assign(prices.size(),vector<int>(2,-1));
        return dfs(0,true,prices);    
    }
private:
    vector<vector<int>> mem;
    int dfs(int i, int buy, vector<int>& prices)
    {
        if(i>=prices.size()) return 0;
        if(mem[i][buy]!=-1) return mem[i][buy];
        int cooldown=dfs(i+1,buy,prices);
        if(buy)
        {
            int b=dfs(i+1,false,prices)-prices[i];
            mem[i][buy]=max(cooldown,b);
        }else{
            int s=dfs(i+2,true,prices)+prices[i];
            mem[i][buy]=max(cooldown,s);
        }
        return mem[i][buy];
    }

};
