class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int res=0;
        int mod=7+1e+9;
        int n=nums.size();
        int l=0;
        sort(nums.begin(),nums.end());
        vector<int> pow2(n,1);
        for(int i=1;i<n;i++)
        {
            pow2[i]=pow2[i-1]*2%mod;
        }
        for(int l=0;l<n;l++)
        {
            int r=n-1;
            while(r>=l&&nums[r]+nums[l]>target)
            {
                r--;
            }
            if(r>=l)
            {
                res=(res+pow2[r-l]) % mod;
            }
        }
        return res;
    }
};