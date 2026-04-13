class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        int res=-1;

        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(nums[m]<=nums[r])
            {
                //m in right sort
                if(target<nums[m]||target>nums[r])
                {
                    r=m-1;
                }else if(target>nums[m])
                {
                    l=m+1;
                }else
                {
                    res=m;
                    break;
                }
            }else{
                //m in left sort
                if(target>nums[m]||target<nums[l])
                {
                    l=m+1;
                }else if(target<nums[m])
                {
                    r=m-1;
                }else
                {
                    res=m;
                    break;
                }
            }
            

        }
        return res;
    }
};
