class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n,INT_MAX);
        dist[k-1]=0;
        for(int i=0;i<n-1;i++)
        {
            for(auto& t:times)
            {
                int s=t[0]-1;
                int e=t[1]-1;
                int ti=t[2];
                if(dist[s]!=INT_MAX &&dist[s]+ti<dist[e]) dist[e]=dist[s]+ti;
            }
        }
        int res=*max_element(dist.begin(),dist.end());
        return res==INT_MAX?-1:res;
    }
};
