class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        vector<pair<int, int>> adj;
        for(int i=0;i<x.size();i++)
        {
            adj.push_back({y[i],x[i]});
        }
        sort(adj.begin(), adj.end());
        int i=adj.size()-1, j=adj.size()-2, k=-1;
        bool j_flag=false;
        bool k_flag=false;
            while(j>0)
            {
                if(adj[j].second==adj[i].second)
                {
                    j--;
                    j_flag=false;
                }else{
                    j_flag=true;
                    break;
                }
            }
            if(j_flag)
            {
                k=j-1;
                while(k>=0)
                {
                    if(adj[k].second==adj[j].second||adj[k].second==adj[i].second)
                    {
                        k--;
                        k_flag=false;
                    }else{
                        k_flag=true;
                        break;
                    }
                }
            }
            if(!j_flag||!k_flag)
            {
                return -1;
            }else{
                return adj[i].first+adj[j].first+adj[k].first;
            }


    }
};