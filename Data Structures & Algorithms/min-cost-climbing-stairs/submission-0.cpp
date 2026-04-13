class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        return min(dfs(cost,0),dfs(cost,1));
    }
    int dfs(vector<int>& cost, int i)
    {
        if(i>cost.size()) return 0;
        if(i==cost.size()) return 0;
        return min(dfs(cost,i+1)+cost[i],dfs(cost,i+2)+cost[i]);
    }
};
