class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            int res=0;
            for(int j=i;j<nums.size();j++)
            {
                res+=nums[j];
                if(res==k) cnt++;
            }
        }
        return cnt;
    }
};