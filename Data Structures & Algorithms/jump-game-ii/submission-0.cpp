class Solution {
public:
    int jump(vector<int>& nums) {
        int res=0,l=0,r=0;

        while(r<nums.size()-1)
        {
            int max_l=0;
            for(int i=l;i<=r;i++)
            {
                max_l=max(max_l, i+nums[i]);
            }
            l=r+1;
            r=max_l;
            res++;
        }
        return res;
    }
};
