class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> dp;
        for(auto c:s)
        {
            dp[c]++;
        }
        for(int i=0;i<s.size();i++)
        {
            if(dp[s[i]]==1) return i; 
        }
        return -1;
    }
};