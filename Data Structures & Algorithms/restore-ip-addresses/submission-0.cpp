class Solution {
    void backtrack(string s, int idx, int dot,string cur, vector<string>& res)
    {
        if(idx>=s.size()&&dot==4)
        {
            res.push_back(cur.substr(0, cur.size()-1));
            return;
        }
        if(dot>=4)
        {
            return;
        }
        for(int i=idx;i<min(idx+3, (int)s.size());i++)
        {
            if(s[idx]=='0'&&i>idx) return;
            if((stoi(s.substr(idx, i-idx+1))<256))
            {
                backtrack(s, i+1, dot+1, cur+s.substr(idx, i-idx+1)+'.', res);
            }
        }
        return;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        backtrack(s, 0, 0, "", res);
        return res;
    }
};