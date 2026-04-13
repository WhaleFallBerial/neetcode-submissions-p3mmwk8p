class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int mins=min(word1.size(),word2.size());
        int maxs=max(word1.size(),word2.size());
        string res;
        for(int i=0;i<mins;i++)
        {
            res+=word1[i];
            res+=word2[i];
        }
        if(word1.size()>word2.size())
        {
            res+=word1.substr(mins);
        }else{
            res+=word2.substr(mins);
        }
        return res;
    }
};