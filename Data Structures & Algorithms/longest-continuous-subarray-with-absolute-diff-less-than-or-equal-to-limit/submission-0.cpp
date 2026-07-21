class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int left=0;
        int right=0;
        int n=nums.size();
        int res=1;
        
        while(left<n)
        {
            multiset<int> ms;
            for(right=left;right<n;right++)
            {
                ms.insert(nums[right]);
                if((*ms.rbegin()-*ms.begin())<=limit)
                {
                    res=max(res, right-left+1);
                }
            }
            left++;
        }
        return res;
    }
};