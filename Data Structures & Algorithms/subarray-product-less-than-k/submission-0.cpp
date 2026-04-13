class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int r=i;
            int tmp=1;
            while(r<n&&nums[r]<k)
            {
                tmp*=nums[r];
                if(tmp>=k)
                    break;
                res++;
                r++;
            }
        }
        return res;
    }
};