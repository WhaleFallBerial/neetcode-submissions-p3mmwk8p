class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(),-1);
        for(auto h=0;h<nums1.size();h++)
        {
            bool flag= false;
            for(int i=0;i<nums2.size();i++)
            {
                if(flag&&nums1[h]<nums2[i])
                {
                    res[h]=nums2[i];
                    break;
                }
                if(nums1[h]==nums2[i])
                {
                    flag=true;
                }
            }
        }
        return res;
    }
};