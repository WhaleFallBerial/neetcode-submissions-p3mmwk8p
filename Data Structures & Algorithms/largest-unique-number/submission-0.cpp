class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        unordered_map<int, int> dp;
        vector<int>adj;
        int res=-1;
        for(auto n:nums)
        {
            dp[n]++;
        }
        for(auto [f,b]:dp)
        {
            if(b!=1) continue;
            
            res=max(f,res);
        }
        return res;
    }
};
