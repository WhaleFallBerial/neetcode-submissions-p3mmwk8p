class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        int res=0;
        vector<int> dist(n,INT_MAX);
        vector<bool> visit(n, false);
        int edge=0;
        int node=0;
        while(edge<n-1)
        {
            visit[node]=true;
            int next=-1;
            for(int i=0;i<n;i++)
            {
                if(visit[i]) continue;
                int cur=abs(points[i][0]-points[node][0])+abs(points[i][1]-points[node][1]);
                dist[i]=min(dist[i],cur);
                if(next==-1||dist[i]<dist[next])
                {
                    next=i;
                }
            }
            res+=dist[next];
            node=next;
            edge++;
        }
        return res;
    }
};
