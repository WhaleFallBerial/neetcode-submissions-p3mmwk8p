class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        vector<string> part;
        dfs(s,part,0,0);
        return res;
    }

    void dfs(string s, vector<string> part, int i, int j)
    {
        if(j>=s.size() )
        {
            if(i==j) res.push_back(part);
            return;
        }

        if(psame(s,i,j))
        {
            part.push_back(s.substr(i,j-i+1));
            dfs(s,part,j+1,j+1);
            part.pop_back();
        }
        dfs(s,part,i, j+1);

    }

    bool psame(string s, int i, int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;j--;
        }
        return true;
    }
};
