class Solution {
    int res=INT_MAX;
    unordered_map<int, int> memo;  // memo[i] = 從位置i開始能達到的最少額外字元數
    void dfs(string& s, unordered_set<string>& words, int i, int extra_c)
    {
        if(extra_c >= res) return;
        if(i==s.size())
        {
            res=min(res,extra_c);
            return;
        }

        if(memo.count(i) && memo[i] <= extra_c) return;
        memo[i] = extra_c;
        dfs(s,words,i+1,extra_c+1);
        for(int j=i;j<s.size();j++)
        {
            string tmp=s.substr(i,j-i+1);
            if(words.count(tmp))
            {
                dfs(s,words,j+1,extra_c);

            }
        }
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
         unordered_set<string> words(dictionary.begin(),dictionary.end());
        dfs(s,words,0,0);
        return res;
    }
};