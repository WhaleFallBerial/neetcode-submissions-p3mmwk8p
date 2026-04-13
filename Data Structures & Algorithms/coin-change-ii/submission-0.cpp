class Solution {
public:
    int change(int amount, vector<int>& coins) {
        mem.assign(coins.size(),vector<int>(amount+1,-1));
        return dfs(0,amount,coins);
    }
private:
    vector<vector<int>>mem;
    int dfs(int i, int a, vector<int>& coins)
    {
        if(a==0) return 1;
        if(a<0) return 0;
        if(i>=coins.size()) return 0;
        if(mem[i][a]!=-1) return mem[i][a];
        int res=0;
        res=dfs(i+1,a,coins);
        res+=dfs(i,a-coins[i],coins);
        mem[i][a]=res;
        return mem[i][a];
    }

};
