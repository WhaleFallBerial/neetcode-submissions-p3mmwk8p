class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res=1;
        for(int i=0;i<nums.size();i++)
        {
            res=max(res,dfs(nums,i));
        }
        return res;
    }
private:
    unordered_map<int, int> mem;
    int dfs(vector<int>& nums, int i)
    {
        if(mem.count(i)) return mem[i];

        int max_len=1;
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[i]<nums[j]) max_len=max(max_len, 1+dfs(nums,j));
        }
        return mem[i]=max_len;
    }
};
