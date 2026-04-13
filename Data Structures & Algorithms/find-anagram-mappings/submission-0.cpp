class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        for(auto n1:nums1)
        {
            for(int i=0;i<nums2.size();i++)
            {
                if(nums2[i]==n1)
                {
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};
