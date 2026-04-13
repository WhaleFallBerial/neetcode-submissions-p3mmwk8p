class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> dp(nums.size());
        int sum=accumulate(nums.begin(),nums.end(),0);
        for(int i=0;i<nums.size();i++)
        {
            int m=(sum-nums[i]);
            if(m%2!=0) 
                dp[i]=-1;
            else
                dp[i]=m/2;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(dp[i]==-1) continue;
            //if(dp[i]==0) return 0;
            int sum_half=accumulate(nums.begin(), nums.begin()+i,0);
            if(sum_half==dp[i]) return i;
        }
        return -1;
    }
};