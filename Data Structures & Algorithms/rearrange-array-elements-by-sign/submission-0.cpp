class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> neg,pos;
        for(auto n:nums)
        {
            if(n>=0)
                pos.push_back(n);
            else
                neg.push_back(n);
        }
        vector<int> res;
        int num=nums.size();
        for(int i=0;i<num/2;i++)
        {
            res.push_back(pos[i]);
            res.push_back(neg[i]);
        }
        return res;
    }
};