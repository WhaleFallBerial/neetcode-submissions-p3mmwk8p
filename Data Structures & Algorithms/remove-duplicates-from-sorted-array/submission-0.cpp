class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int l=0;int r=0;
        while(r<n)
        {
            nums[l]=nums[r];
            while(r<n&&nums[l]==nums[r])
            {
                r++;
            }
            l++;
        }
        return l;
    }
};