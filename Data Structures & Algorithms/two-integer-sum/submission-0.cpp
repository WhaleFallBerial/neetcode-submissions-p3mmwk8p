class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> n;
        for(auto i=0;i<nums.size();i++)
        {
            n[nums[i]]=i;
        }
        for(auto i=0;i<nums.size();i++)
        {
            int diff=target-nums[i];
            if(n.count(diff)&&n[diff]!=i)
            {
                return {i,n[diff]};
            }
        }
    }
};
