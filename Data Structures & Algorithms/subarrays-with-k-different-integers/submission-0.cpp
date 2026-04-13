class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++)
        {
            unordered_set<int> dp;
            int r=i;
            while(r<n&&dp.size()<=k)
            {
                if(!dp.count(nums[r]))
                {
                    dp.insert(nums[r]);
                }
                if(dp.size()==k)
                {
                    res++;
                }
                r++;
            }

        }
        return res;
    }
};