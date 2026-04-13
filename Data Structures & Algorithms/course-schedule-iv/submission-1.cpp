class Solution {
    vector<vector<int>> adj;
    vector<vector<int>> is_check;
    bool dfs(int node, int target)
    {
        if(is_check[node][target]!=-1)
        {
            return is_check[node][target]==1;
        }
        if(node==target) return true;

        for(int n:adj[node])
        {
            if(dfs(n,target)) 
            {
                is_check[n][target]=1;
                return true;
            }
        }
        is_check[node][target]=0;
        return false;
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        adj.assign(numCourses,vector<int>());
        is_check.assign(numCourses,vector<int>(numCourses,-1));
        vector<bool> res;
        for(auto& p:prerequisites)
        {
            adj[p[0]].push_back(p[1]);
            is_check[p[0]][p[1]]=1;
        }
        for(auto& q:queries)
        {
            res.push_back(dfs(q[0],q[1]));
        }
        return res;
    }
};