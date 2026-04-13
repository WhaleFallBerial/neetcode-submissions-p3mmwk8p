class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> adj;
        int res=0;
        for(auto n:nums) adj[n]++;
        for(auto [a,b]:adj)
        {
            if(b==1) return -1;
            res+=(b/3);
            if(b%3!=0) res++;
            
        }
        return res;
    }
};