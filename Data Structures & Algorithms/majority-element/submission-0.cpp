class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> res;
        int maxc=nums.size()/2;
        for(auto& n:nums)
        {
            res[n]++;
            if(res[n]>maxc) return n;
        }

        
    }
};