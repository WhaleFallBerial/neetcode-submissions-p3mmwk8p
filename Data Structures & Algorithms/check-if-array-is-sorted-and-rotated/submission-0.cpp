class Solution {
public:
    bool check(vector<int>& nums) {
        int min_index=min_element(nums.begin(),nums.end())-nums.begin();
        vector<int> adj(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            adj[i]=nums[(i+min_index)%nums.size()];
        }
        int bef=INT_MIN;
        for(auto a:adj)
        {
            if(bef>a) return false;
            bef=a;
        }
        return true;
    }
};