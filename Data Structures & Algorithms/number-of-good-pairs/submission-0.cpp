class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> adj;
        for(auto n:nums)
        {
            adj[n]++;
        }
        int res=0;
        for(auto [a,b]:adj)
        {
            if(b<2) continue;

            int up=1;
            for(int i=(b-1);i<=b;i++)
            {
                up*=i;
            }
            int down=1;
            for(int i=1;i<=2;i++)
            {
                down*=i;
            }
            res+=(up/down);
        }
        return res;
    }
};