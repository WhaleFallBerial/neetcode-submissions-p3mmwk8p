class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<2) return false;
        for(int i=0;i<n;i++)
        {
            int tmp=nums[i];
            for(int j=i+1;j<n;j++)
            {
                tmp+=nums[j];
                if(tmp%k==0) return true;
            }
        }
        return false;
    }
};