class Solution {
    int dfs(int cur, int parent, vector<vector<int>> adj, vector<bool>& hasApple)
    {
        int time=0;
        for(auto c:adj[cur])
        {
            if(c==parent) continue;
            int ct=dfs(c,cur, adj, hasApple);
            if(ct>0||hasApple[c])
            {
                time=time+2+ct;
            }
        }
        return time;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(auto e:edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return dfs(0, -1, adj, hasApple);
    }
};