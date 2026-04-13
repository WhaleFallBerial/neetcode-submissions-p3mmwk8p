class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        vector<int> dualnums(2*n,0);
        for(int i=0;i<n;i++)
        {
            dualnums[i]=nums[i];
            dualnums[i+n]=nums[i];
        }

        int res=nums[0];

        for(int i=0;i<n;i++)
        {
            int sumv=0;
            for(int j=0;j<n;j++)
            {
                sumv+=dualnums[i+j];
                res=max(res, sumv);
            }
        }
        return res;

    }


};