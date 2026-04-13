class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> data(n+1);
       
        for(auto& e:edges)
        {
            
            vector<bool> visit(n+1,false);
            data[e[0]].push_back(e[1]);
            data[e[1]].push_back(e[0]);
            if(!dfs(data,visit, e[0],-1)) return {e[0],e[1]};
            
        }
        return {};
    }
private:
    bool dfs(vector<vector<int>>& data, vector<bool>& visit, int idx, int parent)
    {
       
        visit[idx]=true;
        for(auto& d:data[idx])
        {
            if(d==parent) continue;
            if(visit[d]) return false;
        
                if(!dfs(data,visit, d, idx)) return false;
        }
        return true;
    }
};
