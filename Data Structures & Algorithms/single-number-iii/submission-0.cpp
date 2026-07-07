class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> adj;
        for(auto n:nums)
        {
            if(!adj.count(n))
            {
                adj.insert(n);
            }else{
                adj.erase(n);
            }
        }
        return vector<int>(adj.begin(), adj.end());
    }
};