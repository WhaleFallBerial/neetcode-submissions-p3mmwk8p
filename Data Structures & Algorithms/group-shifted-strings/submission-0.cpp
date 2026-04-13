class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        int n=strings.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
        {
            int m=strings[i].size();
            for(int j=0;j<m-1;j++)
            {
                adj[i].push_back((26+strings[i][j+1]-strings[i][j])%26);
            }            
        }

        vector<vector<int>> comp;

        for(int i=0;i<n;i++)
        {
            int flag=0;
            for(int j=0;j<comp.size();j++)
            {
                if(comp[j]==adj[i])
                {
                    flag=1;
                    res[j].push_back(strings[i]);
                    break;
                }
            }
            if(!flag)
            {
                comp.push_back({adj[i]});
                res.push_back({strings[i]});
            }
        }
        return res;

    }
};
