class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it=find(nums.begin(),nums.end(),target);
        if(it==nums.end())
        {
            return vector<int>{-1,-1};
        }else{
            int i=it-nums.begin();
            int n=nums.size();
            for(int j=i;j<n;j++)
            {
                if(nums[j]!=target)
                {
                    return vector<int>{i,j-1};
                }
            }
            return vector<int>{i,n-1};
        }
    }
};