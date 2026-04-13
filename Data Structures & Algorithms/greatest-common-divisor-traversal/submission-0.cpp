class Solution {
    void dfs(int i, vector<vector<int>>& adj, vector<bool>& visit)
    {
        visit[i]=true;
        for(auto a:adj[i])
        {
            if(!visit[a])
                dfs(a,adj,visit);
        }

    }
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n=nums.size();
        vector<bool> visit(n,false);
        vector<vector<int>> adj(n);

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(__gcd(nums[i],nums[j])>1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        dfs(0, adj, visit);
        for(auto v:visit)
        {
            if(!v) return false;
        }
        return true;
    }

};