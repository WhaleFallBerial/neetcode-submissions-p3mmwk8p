class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for(auto& n:nums)
        {
            if(target==n) return true;
        }
        return false;
    }
};