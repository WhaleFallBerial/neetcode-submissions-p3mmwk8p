class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int increaseing_flag=-1;

        for(auto i=0;i<nums.size()-1;i++)
        {
            if(increaseing_flag==1&&nums[i]>nums[i+1])
            {
                return false;
            }else if(increaseing_flag==0&&nums[i]<nums[i+1])
            {
                return false;
            }else{
                if(nums[i]>nums[i+1])
                {
                    increaseing_flag=0;
                }else if(nums[i]<nums[i+1]){
                    increaseing_flag=1;
                }
            }
        }
        return true;
    }
};