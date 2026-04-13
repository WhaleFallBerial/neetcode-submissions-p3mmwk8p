class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1;
        unordered_set<int> res;
        for(auto n:nums1)
        {
            n1.insert(n);
        }
        for(auto n:nums2)
        {
            if(n1.find(n)!=n1.end())
            {
                res.insert(n);
            }
        }
        return vector<int>(res.begin(),res.end());
    }
};