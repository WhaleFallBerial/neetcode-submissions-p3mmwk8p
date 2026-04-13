class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int minv=*min_element(nums.begin(), nums.end());
        int maxv=*max_element(nums.begin(), nums.end());
        for(auto& n:nums)
        {
            cnt[n]++;
        }
        int i=0;
        for(int val=minv;val<=maxv;val++)
        {
            while(cnt[val]>0)
            {
                nums[i]=val;
                cnt[val]--;
                i++;
            }
        }
        return nums;
    }
};