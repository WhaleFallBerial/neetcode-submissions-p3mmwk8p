class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> ws;
        for(int i=0;i<26;i++)
        {
            ws[order[i]]=i;
        }
        int n=words.size();
        for(int i=0;i<n-1;i++)
        {
            string w1=words[i],w2=words[i+1];
            for(int j=0;j<w1.size();j++)
            {
                if(j==w2.size()) return false;
                if(w1[j]!=w2[j])
                {
                    if(ws[w1[j]]>ws[w2[j]]) return false;
                    break;
                }
            }
        }
        return true;
    }
};