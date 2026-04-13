class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=0;
        int n=nums.size();
        int max_cnt=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i])
            {
                res++;
            } else{
                max_cnt=max(max_cnt, res);
                res=0;
            }
        }
        max_cnt=max(max_cnt, res);
        return max_cnt;
    }
};