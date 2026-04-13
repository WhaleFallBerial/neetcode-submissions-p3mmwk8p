class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res(2);
        unordered_set<int> n1, n2;
        for(auto n:nums1) n1.insert(n);
        for(auto n:nums2) n2.insert(n);
        for(auto n:n1)
        {
            if(!n2.count(n)) res[0].push_back(n);
        }
        for(auto n:n2)
        {
            if(!n1.count(n)) res[1].push_back(n);
        }
        return res;
    }
};