class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int res=1;
        for(int i=1;i<nums.size();i++)
        {
            int adj=k;
            int cnt=1;
            int j=i-1;
            while(j>=0)
            {
                adj-=(nums[i]-nums[j]);
                if(adj<0)
                {
                    break;
                }else{
                    cnt++;
                }
                j--;
            }
            res=max(res,cnt);
        }
        return res;
    }
};