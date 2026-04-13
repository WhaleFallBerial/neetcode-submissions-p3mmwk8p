class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()>n-1) return false;

        unordered_set<int> visit;
        vector<vector<int>> data(n);
        for(auto& e: edges)
        {
            data[e[0]].push_back(e[1]);
            data[e[1]].push_back(e[0]);
        }
        if(!dfs(data,visit,0,-1)) return false;

        return visit.size()==n;
    }
private:
    bool dfs(vector<vector<int>>& data, unordered_set<int>& visit,int n,int par)
    {
        if(visit.count(n)) return false;
        visit.insert(n);
        for(auto& d:data[n])
        {
            if(d==par) continue;
            if(!dfs(data,visit,d,n)) return false;
        }
        return true;
    }
};
