class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        dp[s.size()]=true;
        return dfs(s,wordDict,0);

    }
private:
    unordered_map<int,bool> dp;
    int dfs(string s, vector<string>& wordDict, int i)
    {
        if(dp.count(i)) return dp[i];
        for(string& w:wordDict)
        {
            if(i+w.size()<=s.size()&&s.substr(i,w.size())==w)
            {
                if(dfs(s,wordDict,i+w.size()))
                {
                    dp[i]=true;
                    return dp[i];
                }
            }
        }
        dp[i]=false;
        return dp[i];
    }
};
