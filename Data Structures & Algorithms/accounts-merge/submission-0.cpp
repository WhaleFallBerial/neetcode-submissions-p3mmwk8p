class UnionFind{
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind(int n)
    {
        parent.resize(n);
        rank.resize(n,1);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }

    int find(int x)
    {
        if(x!=parent[x])
        {
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }

    bool union_set(int x1, int x2)
    {
        int p1=find(x1);
        int p2=find(x2);
        if(p1==p2)
        {
            return false;
        }

        if(rank[p1]>rank[p2])
        {
            parent[p2]=p1;
            rank[p1]+=rank[p2];
        }else{
            parent[p1]=p2;
            rank[p1]+=rank[p2];
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> email_to_acc;
        int n=accounts.size();
        UnionFind uf(n);
        
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                if(email_to_acc.count(accounts[i][j]))
                {
                    uf.union_set(i,email_to_acc[accounts[i][j]]);
                }else{
                    email_to_acc[accounts[i][j]]=i;
                }
            }
        }

        map<int, vector<string>> email_group;
        for(const auto& [e,a]:email_to_acc)
        {
            email_group[uf.find(a)].push_back(e);
        }
        vector<vector<string>> res;
        for(auto& [a,e]:email_group)
        {
            sort(e.begin(),e.end());
            vector<string> merged;
            merged.push_back(accounts[a][0]);
            merged.insert(merged.end(),e.begin(),e.end());
            res.push_back(merged);
        }
        return res;
    }
};