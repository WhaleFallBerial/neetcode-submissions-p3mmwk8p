class Solution {
public:
    int rob(vector<int>& nums) {
        mem.assign(nums.size(),-1);
        return dfs(nums,0);
    }
private:
    vector<int> mem;
    int dfs(vector<int>& nums,int i)
    {
        if(i>=nums.size()) return 0;
        if(mem[i]!=-1) return mem[i];
        mem[i]=max(nums[i]+dfs(nums,i+2),dfs(nums,i+1));
        return mem[i];
    }
};
