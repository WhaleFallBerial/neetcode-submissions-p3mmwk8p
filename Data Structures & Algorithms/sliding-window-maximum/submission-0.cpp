class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        
        for(auto i=0;i<nums.size()-k+1;i++)
        {   
            int currmax=nums[i];  
            for(auto j=i;j<i+k;j++)
            {
                currmax=max(currmax,nums[j]);
            }
            res.push_back(currmax);
        }
        return res;
    }
};
