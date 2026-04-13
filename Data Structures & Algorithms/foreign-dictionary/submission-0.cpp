class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        for(const auto& w:words)
        {
            for(const auto& c:w)
            {
                adj[c];
            }
        }    
        for(int i=0;i<words.size()-1;i++)
        {
            string s1=words[i], s2=words[i+1];
            size_t len=min(s1.size(),s2.size());
            if(s1.size()>s2.size() && s1.substr(0,len)==s2.substr(0,len)) return"";
            for(int j=0;j<len;j++)
            {
                if(s1[j]!=s2[j]) 
                {
                    adj[s1[j]].insert(s2[j]);
                    break;
                }
            }
        }

        for(const auto& p:adj)
        {
            if(dfs(p.first)) return"";
        }
        reverse(res.begin(),res.end());
        return res;
    }

private:
    unordered_map<char,unordered_set<char>> adj;
    unordered_map<char,bool> visit;
    string res;

    bool dfs(char c)
    {
        if(visit.find(c)!=visit.end()) return visit[c];
        visit[c]=true;
        for(auto& n:adj[c])
        {
            if(dfs(n)) return true;
        }
        visit[c]=false;
        res.push_back(c);
        return false;
    }

};
