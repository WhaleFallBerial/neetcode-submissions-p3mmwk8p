class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int index=0;
        vector<char> adj;
        int res=0;
        for(auto k:keyboard)
        {
            adj.push_back(k);
        }
        for(auto w:word)
        {
            int cnt=(find(adj.begin(),adj.end(),w)-adj.begin());
            res=res+abs(cnt-index);
            index=cnt;
        }
        return res;
    }
};
