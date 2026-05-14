class Solution {
    int dfs(int f, int b, string& s, vector<vector<int>>& dp)
    {
        if(f>b) return 0;
        if(f==b) return 1;
        if(dp[f][b]!=-1) return dp[f][b];
        if(s[f]==s[b])
        {
            dp[f][b]=dfs(f+1, b-1, s, dp)+2;
        }else{
            dp[f][b]=max(dfs(f+1, b, s, dp), dfs(f, b-1, s, dp));
        }

        return dp[f][b];
    }
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return dfs(0,n-1, s, dp);
    }
};