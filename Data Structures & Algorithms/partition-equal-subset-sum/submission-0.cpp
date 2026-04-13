class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto& n:nums)
        {
            sum+=n;
        }
        if(sum%2!=0) return false;
        mem.resize(nums.size(),vector<int>(sum/2+1,-1));
       return dfs(nums,0,sum/2);
    }
private:
    vector<vector<int>> mem;

    bool dfs(vector<int>& nums, int i, int target)
    {
        if(i==nums.size()) return target==0;
        if(target<0) return false;
        if(mem[i][target]!=-1) return mem[i][target];

        mem[i][target]=dfs(nums,i+1,target)||dfs(nums,i+1,target-nums[i]);
        return mem[i][target];
    }
};
