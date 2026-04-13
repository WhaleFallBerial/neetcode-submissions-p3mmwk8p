class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> data(n);
        vector<int> visit(n,false);
        int res=0;
        for(auto& e:edges)
        {
            data[e[0]].push_back(e[1]);
            data[e[1]].push_back(e[0]);
        }

        for(int i=0;i<n;i++)
        {
            if(!visit[i])
            {
                dfs(i,data,visit);
                res++;
            }
        }
        return res;
    }
private:
    void dfs(int idx,vector<vector<int>>& data, vector<int>& visit)
    {
        if(visit[idx]) return;
        visit[idx]=true;
        for(auto& d:data[idx])
        {
            if(!visit[d]) dfs(d,data, visit);
        }
    }
};
