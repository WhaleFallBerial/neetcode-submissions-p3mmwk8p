class Solution {
    bool dfs(vector<int>& nums, int k, int target, int start, int count, int sum)
    {
        if(count==k)
        {
            return sum==target;
        }

        if(sum>target)
        {
            return false;
        }

        if(k-count>nums.size()-start)
        {
            return false;
        }

        int remain=k-count;
        for(int i=start; i<=nums.size()-remain;i++)
        {
            if (i > start && nums[i] == nums[i - 1]) continue;
            if(dfs(nums, k, target, i+1, count+1, sum+nums[i]))
            {
                return true;
            }
        }

        return false;
        
    }
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(), nums.end(),0);
        sort(nums.begin(), nums.end());
        for(int i=1;i<=n/2;i++)
        {
            if(sum*i%n!=0) continue;
            int target=sum*i/n;
            if(dfs(nums, i, target, 0,0,0))
            {
                return true;
            }
        }
        return false;
    }
};