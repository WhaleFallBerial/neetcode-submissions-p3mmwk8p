class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res=0;
        int sum=0;
        bool flag=false;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1]&&!flag)
            {
                sum=nums[i-1];
                sum+=nums[i];
                flag=true;
            }else if(nums[i]>nums[i-1]&&flag)
            {
                sum+=nums[i];
            }
            else{
                flag=false;
                res=max(res,sum);
                sum=0;
            }
        }
        res=max(res,sum);
        if(res==0) res=*max_element(nums.begin(),nums.end());
        return res;

    }
};