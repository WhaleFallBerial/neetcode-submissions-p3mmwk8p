class Solution {
    unordered_set<string> words;
    vector<string> res;
    void dfs(string s, int i, vector<string>& cur)
    {
        if(i==s.size())
        {
            res.push_back(joins(cur));
            return;
        }
        for(int j=i;j<s.size();j++)
        {
            string tmp=s.substr(i,j-i+1);
            if(words.count(tmp))
            {
                cur.push_back(tmp);
                dfs(s,j+1,cur);
                cur.pop_back();
            }
        }
    }
    string joins(vector<string>& cur)
    {
        ostringstream oss;
        for(int i=0;i<cur.size();i++)
        {
            if(i>0) oss<<" ";
            oss<<cur[i];
        }
        return oss.str();
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        words=unordered_set<string>(wordDict.begin(),wordDict.end());
        vector<string> cur;
        dfs(s,0, cur);
        return res;
    }
};