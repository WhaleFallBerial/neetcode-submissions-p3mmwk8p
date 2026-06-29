class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<vector<char>> dp(numRows);
        int idx=0;
        int i=0;
        while(i<s.size())
        {    
            while(idx<numRows&&i<s.size())
            {
                dp[idx++].push_back(s[i++]);
            }
            idx=numRows-2;
            while(idx>0&&i<s.size())
            {
                dp[idx--].push_back(s[i++]);
            }
            idx=0;
        }
        string res;
        for(auto d:dp)
        {
            for(auto c:d)
            {
                res+=c;
            }
        }
        return res;
    }
};