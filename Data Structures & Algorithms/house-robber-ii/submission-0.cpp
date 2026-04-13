class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        mem.assign(nums.size(),vector<int>(2,-1));
        return max(dfs(nums,0,1),dfs(nums,1,0));
    }
    vector<vector<int>> mem;
    int dfs(vector<int>& nums, int i, int flag)
    {
        if(i>=nums.size()||(flag==1&&i==nums.size()-1)) return 0;
        if(mem[i][flag]!=-1) return mem[i][flag];
        mem[i][flag]=max(dfs(nums,i+1,flag),nums[i]+dfs(nums,i+2,flag|i==0?1:0));
        return mem[i][flag];
    }
};
