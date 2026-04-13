class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n=nums.size();
        if(n%2!=0) return false;
        unordered_map<int, int> dp;
        for(auto m:nums)
        {
            dp[m]++;
        }
        if(dp.size()>n/2) return false;
        for(auto [a,b]:dp)
        {
            if(b%2!=0) return false;
        }
        return true;
    }
};