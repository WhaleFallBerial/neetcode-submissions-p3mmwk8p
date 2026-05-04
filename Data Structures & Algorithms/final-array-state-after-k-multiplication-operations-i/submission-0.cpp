class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<int> res=nums;
        for(int i=0;i<k;i++)
        {
            int idx=min_element(res.begin(), res.end())-res.begin();
            res[idx]=res[idx]*multiplier;
        }
        return res;
    }
};