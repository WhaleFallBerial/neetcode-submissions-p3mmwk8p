class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        double res=0.0;
        if(start_node==end_node)
        {
            return 1;
        }
        unordered_map<int, vector<pair<int, double>>> mp;
        for(int i=0;i<edges.size();i++)
        {
            mp[edges[i][0]].push_back({edges[i][1], succProb[i]});
            mp[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<double> maxp(n, 0.0);
        maxp[start_node]=1.0;
         priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});

        while (!pq.empty()) {
            auto [p, node] = pq.top(); pq.pop();
            if (node == end_node) break;   // 第一次彈出終點就是最大機率
            if (p < maxp[node]) continue;

            for (auto [nei, prob] : mp[node]) {
                double newp = p * prob;
                if (newp > maxp[nei]) {
                    maxp[nei] = newp;
                    pq.push({newp, nei});
                }
            }
        }
        return maxp[end_node];
    }
};