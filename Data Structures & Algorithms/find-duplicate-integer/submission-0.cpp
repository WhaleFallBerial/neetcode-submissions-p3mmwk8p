class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(auto i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
            {
                return nums[i];
            }
        }
        return -1;
    }
};
