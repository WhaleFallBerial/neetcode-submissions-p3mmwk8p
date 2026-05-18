class Solution {
    int dfs(vector<vector<int>>& envelopes, int pre, int i, int n, vector<vector<int>>& dp)
    {
        if(i>=n)
        {
            return 0;
        }

        if(dp[i][pre+1]!=-1) return dp[i][pre+1];
        int r, c;
        if(pre==-1)
        {
            r=0; 
            c=0;
        }else{
            r=envelopes[pre][0];
            c=envelopes[pre][1];
        }

        if(r>=envelopes[i][0]||c>=envelopes[i][1])
        {
            dp[i][pre+1]=dfs(envelopes, pre, i+1, n, dp);
        }else{
            dp[i][pre+1]=max(dfs(envelopes, i, i+1, n, dp)+1,dfs(envelopes, pre, i+1, n, dp));
        }
        
        return dp[i][pre+1];
        

    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        int n=envelopes.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        
        return dfs(envelopes, -1,0,n,dp);
    }
};