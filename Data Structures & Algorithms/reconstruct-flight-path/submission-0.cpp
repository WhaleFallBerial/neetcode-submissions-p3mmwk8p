class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
       unordered_map<string,vector<string>> adj;
       for(auto& t:tickets)
       {
        adj[t[0]].push_back(t[1]);
       }
       for(auto& [src, dst]:adj)
       {
        sort(dst.rbegin(),dst.rend());
       }
       vector<string> res;
       stack<string> stk;
       stk.push("JFK");
       while(!stk.empty())
       {
        string cur=stk.top();
        if(adj[cur].empty())
        {
            res.push_back(cur);
            stk.pop();
        }else{
            string next=adj[cur].back();
            adj[cur].pop_back();
            stk.push(next);
        }
       }
       reverse(res.begin(),res.end());
       return res;
    }
};
