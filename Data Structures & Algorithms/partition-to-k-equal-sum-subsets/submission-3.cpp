class Solution {
    bool dfs(vector<int>& nums, vector<int>& side, int k, int avg, int i)
    {
        if(i==nums.size()) {
            return true;
        }

        for(int j=0;j<k;j++)
        {
            if(j > 0 && side[j] == side[j-1]) continue;
            if(side[j]+nums[i]<=avg)
            {
                side[j]+=nums[i];
                if(dfs(nums,side,k,avg,i+1)) return true;
                side[j]-=nums[i];
            }
            if(side[j] == 0) break;
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        vector<int> side(k,0);
        int total=0;
        int avg=0;
        for(auto& n:nums)
        {
            total+=n;
        }
        if(total%k!=0) return false;
        avg=total/k;
        for(auto& n : nums) {
          if(n > avg) return false; 
        }
        sort(nums.rbegin(),nums.rend());
        return dfs(nums,side,k,avg,0);
    }
};