class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return {};
        sort(nums.begin(), nums.end());
        vector<int>dp(n, 1);
        vector<int>parent(n, -1);
        int maxcnt=1;
        int maxidx=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0&&dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                    parent[i]=j;
                }

                

            }
            if(dp[i]>maxcnt)
                {
                    maxcnt=dp[i];
                    maxidx=i;
                }
        }

        vector<int> res;
        int curidx=maxidx;
        while(curidx!=-1)
        {
            res.push_back(nums[curidx]);
            curidx=parent[curidx];
        }
        
        return res;
    }
};