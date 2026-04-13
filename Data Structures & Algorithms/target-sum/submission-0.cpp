class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        for(auto& n:nums)
        {
            total+=n;
        }
        mem.assign(nums.size(),vector<int>(2*total+1,-1));
        return dfs(0,target,nums);
    }
private:
vector<vector<int>> mem;
int total=0;
    int dfs(int i,int t, vector<int>& nums)
    {
        if(t>total) return 0;
        if(i==nums.size()&&t==0) return 1;
        if(i>=nums.size()) return 0;
        if(mem[i][t+total]!=-1) return mem[i][t+total];
        int res=0;
        res=dfs(i+1,t-nums[i], nums);
        res+=dfs(i+1,t+nums[i],nums);
        mem[i][t+total]=res;
        return mem[i][t+total];

    }
};
