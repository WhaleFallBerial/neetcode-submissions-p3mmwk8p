class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        unordered_map<char,int> count;
        for(auto i=0; i<s.length();i++)
        {
            count[s[i]]++;
            count[t[i]]--;
        }
        for(auto& k : count)
        {
            if(k.second!=0)
            {
                return false;
            }
        }
        return true;
    }
};
