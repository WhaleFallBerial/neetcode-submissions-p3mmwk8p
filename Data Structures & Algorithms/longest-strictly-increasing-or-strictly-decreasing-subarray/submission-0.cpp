class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int res=0;
        int n=nums.size();
        int cnt=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]>nums[i])
            {
                cnt++;
            }else{
                res=max(cnt, res);
                cnt=0;
            }
        }
        res=max(cnt, res);
        cnt=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]<nums[i])
            {
                cnt++;
            }else{
                res=max(cnt, res);
                cnt=0;
            }
        }
        res=max(cnt, res);
        
        return res+1;
    }
};