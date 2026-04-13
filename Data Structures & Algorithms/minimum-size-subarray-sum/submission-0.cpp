class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int l=0;
       int total=0;
       int res=INT_MAX;
       int n=nums.size();
       for(int r=0;r<n;r++)
       {
        total+=nums[r];
        while(total>=target)
        {
            res=min(res,r-l+1);
            total-=nums[l];
            l++;
        }
       }
       return res==INT_MAX?0:res ;
    }
};