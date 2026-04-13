class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> cm;
        unordered_map<string, int> sm;
        int n=pattern.size();
        int i=0;
        stringstream ss(s);
        for(string w;ss>>w;i++)
        {
            if(i>=n||sm[w]!=cm[pattern[i]])
            {
                return false;
            }
            sm[w]=cm[pattern[i]]=i+1;
        }
        return i==n;
    }
};