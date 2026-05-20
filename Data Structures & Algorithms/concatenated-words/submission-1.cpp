class Solution {
    bool dfs(unordered_set<string>& s, unordered_map<string,bool>& dp, string w)
    {
        if(dp.count(w))
        {
            return dp[w];
        }

        for(int i=1;i<w.size();i++)
        {
            string prefix=w.substr(0, i);
            string suffix=w.substr(i);
            if((s.count(prefix)&&s.count(suffix))||(s.count(prefix)&&dfs(s, dp, suffix)))
            {
                dp[w]=true;
                return dp[w];
            }
        }
        dp[w]=false;
        return dp[w];


    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n=words.size();
        vector<string> res;
        unordered_set<string>s(words.begin(), words.end());
        unordered_map<string, bool> dp;
        for(auto w:words)
        {
            if(dfs(s, dp, w))
            {
                res.push_back(w);
            }
        }
        return res;
    
    
    }
};