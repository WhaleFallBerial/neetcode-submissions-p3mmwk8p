class Solution {
    bool checker(string s, string t)
    {
        unordered_map<char, char> trans;
        for(int i=0;i<s.size();i++)
        {
            if(trans.count(s[i])&&trans[s[i]]!=t[i])
                return false;

            trans[s[i]]=t[i];
        }
        return true;
    }
public:
    bool isIsomorphic(string s, string t) {
        return checker(s,t)&&checker(t,s);
    }
};