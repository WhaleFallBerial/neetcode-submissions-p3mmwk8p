class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> cnt;
        unordered_set<int>res;
        for(auto& n:nums)
        {
            cnt[n]++;
            if(cnt[n]>(nums.size()/3))
            {
                res.insert(n);
            }
        }
        return vector<int>(res.begin(),res.end());
    }
};