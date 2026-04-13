class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for(auto& n:nums)
        {
            cnt[n]++;
        }
        int maxv=*max_element(nums.begin(),nums.end());
        int minv=*min_element(nums.begin(),nums.end());
        int index=0;
        for(auto i=minv;i<=maxv;i++)
        {
            while(cnt[i]>0)
            {
                nums[index]=i;
                index++;
                cnt[i]--;
            }
        }
    }
};