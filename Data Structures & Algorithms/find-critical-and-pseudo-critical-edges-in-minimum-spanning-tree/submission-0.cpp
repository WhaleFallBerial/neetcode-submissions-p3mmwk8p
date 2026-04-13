class UnionFind{
    public:
        vector<int> parent, rank;
        UnionFind(int n)
        {
            parent.resize(n);
            rank.resize(n,0);
            for(int i=0;i<n;i++)
            {
                parent[i]=i;
            }
        }

        int find(int x)
        {
            if(parent[x]!=x)
            {
                parent[x]=find(parent[x]);
            }
            return parent[x];
        }

        bool unite(int x, int y)
        {   
            int px=find(x),py=find(y);
            if(px==py) return false;

            if(rank[px]<rank[py]) swap(px,py);
            parent[py]=px;
            if(rank[px]==rank[py]) rank[px]++;
            return true;
        }
};

class Solution {
public:
    int get_weight(int n, vector<vector<int>>& edges, int skip, int must)
    {
        int weight=0;
        int ecount=0;
        UnionFind uf(n);
        if(must!=-1)
        {
            uf.unite(edges[must][0],edges[must][1]);
            weight+=edges[must][2];
            ecount++;
        }

        for(int i=0;i<edges.size();i++)
        {
            if(i==skip) continue;
            if(i==must) continue;

            if(uf.unite(edges[i][0],edges[i][1]))
            {
                weight+=edges[i][2];
                ecount++;
            }

        }
    
        if(ecount!=n-1) return INT_MAX;
        return weight;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i=0;i<edges.size();i++)
        {
            edges[i].push_back(i);
        }
        sort(edges.begin(),edges.end(),[](auto& a, auto& b){ return a[2]<b[2];});
        int orginal_weight=get_weight(n, edges, -1, -1);
        vector<int> critical,pseudo;
        for(int i=0;i<edges.size();i++)
        {
            int edge_index=edges[i][3];
            if(get_weight(n, edges, i, -1)>orginal_weight)
            {
                critical.push_back(edge_index);
                continue;
            }

            if(get_weight(n, edges, -1, i)==orginal_weight)
            {
                pseudo.push_back(edge_index);
            }

        }
        return {critical,pseudo};
        


    }
};