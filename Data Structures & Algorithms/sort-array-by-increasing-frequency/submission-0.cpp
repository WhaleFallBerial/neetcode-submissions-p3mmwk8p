class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> dp;
        vector<int> res;
        for(auto n:nums)
        {
            dp[n]++;
        }
        int s=nums.size();
        map<int, vector<int>> adj;
        for(auto [a, b]:dp)
        {
            adj[b].push_back(a);
        }
        for(auto [a,f]:adj)
        {
            sort(f.rbegin(), f.rend());
            for(auto b:f)
            {
                for(int i=0;i<a;i++)
                {
                    res.push_back(b);
                }
                
            }
        }
        return res;
    }
};