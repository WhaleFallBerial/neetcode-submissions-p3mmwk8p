class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> dp;
        unordered_set<char> odp(order.begin(),order.end());
        for(auto c:s)
        {
            dp[c]++;
        }
        string res;
        for(auto o:order)
        {
            if(dp.count(o))
            {
                for(int i=0;i<dp[o];i++)
                {
                    res+=o;
                }
            }
        }
        for(auto c:s)
        {
            if(!odp.count(c))
            {
                res+=c;
            }
        }
        return res;
    }
};