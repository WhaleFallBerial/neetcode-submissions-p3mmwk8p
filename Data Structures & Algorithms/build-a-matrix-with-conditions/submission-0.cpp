class Solution {
    unordered_set<int> visit;
    unordered_set<int> path;
    vector<int>order;
    vector<int> topart(int k, vector<vector<int>>& edges)
    {
        vector<vector<int>> adj(k+1);
        for(auto& e:edges)
        {
            adj[e[0]].push_back(e[1]);
        }
        visit.clear();
        path.clear();
        order.clear();
        for(int i=1;i<=k;i++)
        {
            if(!dfs(i,adj))
                return {};
        }
        reverse(order.begin(),order.end());
        return order;
    }

    bool dfs(int i, vector<vector<int>>& adj)
    {
      if(path.find(i)!=path.end()) return false;
      if(visit.find(i)!=visit.end()) return true;
    
      path.insert(i);
      visit.insert(i);
        for(auto& x:adj[i])
        {
            if(!dfs(x,adj)) return false;
        }
        path.erase(i);
        order.push_back(i);
        return true;
      
    }
    
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int>row=topart(k,rowConditions);
        if(row.empty()) return {};
        vector<int>col=topart(k,colConditions);
        if(col.empty()) return {};

        vector<int> valc(row.size()+1),valr(col.size()+1);
        for(int i=0;i<row.size();i++)
        {
            valr[row[i]]=i;
        }
        for(int i=0;i<col.size();i++)
        {
            valc[col[i]]=i;
        }
        vector<vector<int>>res(k, vector<int>(k,0));
        for(int i=1;i<=k;i++)
        {
            res[valr[i]][valc[i]]=i;
        }
        return res;
    }
};