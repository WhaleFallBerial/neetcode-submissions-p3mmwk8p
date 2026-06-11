class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int, int> cnt;
        int res=0;
        for(auto num:nums)
        {
            int prev=max(cnt[num], cnt[k]);
            cnt[num]=prev+1;
            res=max(res, cnt[num]-cnt[k]);
        }
        return res+cnt[k];


    }
};