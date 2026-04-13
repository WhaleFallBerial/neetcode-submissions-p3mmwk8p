class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int miss=1;
        sort(nums.begin(),nums.end());
        for(auto& n:nums)
        {
            if(n>0&&miss==n) miss++;
        }
        return miss;
    }
};