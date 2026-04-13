class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int index=(max_element(nums.begin(),nums.end())-nums.begin());
        return index;
    }
};