class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> dp;
        for(int i=0;i<edges.size();i++)
        {
            dp[edges[i][0]].push_back(edges[i][1]);
            dp[edges[i][1]].push_back(edges[i][0]);
        }
        int minh=INT_MAX;
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            int curh=dfs(i, -1,dp);
            if(curh==minh)
            {
                res.push_back(i);
            }else if(curh<minh)
            {
                minh=curh;
                res={i};
            }
        }
        return res;
    }

    int dfs(int i, int parent, unordered_map<int, vector<int>>& dp)
    {  
        int pathlongest=0;
        for(auto d:dp[i])
        {
            if(parent==d) continue;

            pathlongest=max(pathlongest,1+dfs(d,i,dp));
        }
        return pathlongest;

    }

};