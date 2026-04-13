class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> target_str;
        for(auto c: t)
        {
            target_str[c]++;
        }
        int length=INT_MAX;
        pair<int, int> res={-1,-1};
        for(auto i=0;i<s.length();i++)
        {
            unordered_map<char, int> count;
            for(auto j=i; j<s.length(); j++)
            {
                count[s[j]]++;
                int flag=true;
                for(auto [c,cnt]:target_str)
                {
                    if(count[c]<cnt)
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag && (j-i+1)<length)
                {
                    length=j-i+1;
                    res={i,j};
                }
                    
            }
        }
        return length == INT_MAX?"":s.substr(res.first,length);      
    }
};
