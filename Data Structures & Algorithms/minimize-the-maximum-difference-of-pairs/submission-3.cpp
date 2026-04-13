class Solution {
    int dfs(int i, int pairs, vector<int>& nums, int p, unordered_map<long, int>& dp)
    {
        if(pairs==p) return 0;
        if(i>=nums.size()-1) return INT_MAX;
        long long key=i;
        key=key<<32|pairs;
        if(dp.count(key)) return dp[key];

        int take=max(nums[i+1]-nums[i], dfs(i+2,pairs+1,nums,p,dp));
        int skip=dfs(i+1,pairs,nums,p,dp);
        
        return dp[key]=min(take,skip);
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        unordered_map<long,int> dp; 
        return dfs(0,0,nums,p,dp);
    }
};