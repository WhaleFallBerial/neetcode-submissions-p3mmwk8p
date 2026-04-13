class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res="";
        int len=INT_MAX;
        for(auto s:strs)
        {
            len=min(len,static_cast<int>(s.size()));
        }
        for(int i=0;i<len;i++)
        {
            for(auto s:strs)
            {
                if(strs[0][i]!=s[i]) return res;
            }  
            res.push_back(strs[0][i]);
        }
        return res;

    }
};