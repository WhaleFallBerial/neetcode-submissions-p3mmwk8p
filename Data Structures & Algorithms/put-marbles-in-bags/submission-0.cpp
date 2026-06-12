class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        if(k==1) return 0LL;
        vector<int> adj;
        for(int i=0;i<n-1;i++)
        {
            adj.push_back(weights[i]+weights[i+1]);
        }
        sort(adj.begin(), adj.end());

        long long minv=0, maxv=0;
        int m=adj.size();
        for(int i=0;i<k-1;i++)
        {
            minv+=adj[i];
            maxv+=adj[m-1-i];
        }
        return maxv-minv;

    }
};