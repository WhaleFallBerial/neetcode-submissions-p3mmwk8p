class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> dp;
        for(auto m:nums)
        {
            if(dp.find(m)==dp.end()) dp.insert(m);
        }
        vector<int> res;
        for(int i=1;i<=n;i++)
        {
            if(!dp.count(i)) res.push_back(i);
        }
        return res;
    }
};