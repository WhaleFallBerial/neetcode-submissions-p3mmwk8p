class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++)
        {
            int r=i;
            int tmp=0;
            while(r<n&&tmp<=goal)
            {
                tmp+=nums[r];
                if(tmp==goal)
                {
                    res++;
                }
                r++;
            }
        }
        return res;
    }
};