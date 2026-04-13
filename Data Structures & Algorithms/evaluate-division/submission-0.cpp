class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string,double>>> adj;
        for(auto i=0;i<equations.size();i++)
        {
            adj[equations[i][0]].emplace_back(equations[i][1],values[i]);
            adj[equations[i][1]].emplace_back(equations[i][0],1.0/values[i]);
        } 

        vector<double> res;
        for(auto q:queries)
        {
            res.push_back(dfs(q[0],q[1],adj,unordered_set<string>()));
        }
        return res;
    }

    double dfs(string src, string tar, unordered_map<string,vector<pair<string,double>>>& adj, unordered_set<string> visited)
    {
        if(!adj.count(src)||!adj.count(tar)) return -1.0;
        if(src==tar) return 1.0;

        visited.insert(src);
        for(int i=0;i<adj[src].size();i++)
        {
            if(!visited.count(adj[src][i].first))
            {
                double res=dfs(adj[src][i].first,tar,adj,visited);
                if(res!=-1.0)
                    return adj[src][i].second*res;
            }
        }
        return -1.0;
    }
};