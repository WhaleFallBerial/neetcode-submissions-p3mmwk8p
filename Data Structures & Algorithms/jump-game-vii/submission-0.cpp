class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
       int n= s.size();
       vector<int> dp(n,-1);
       dp[n-1]=1;
       if(s[n-1]=='1') return false;
       return dfs(s,0,minJump,maxJump,n, dp);
    }

    bool dfs(const string& s, int i, const int& minJump, const int& maxJump, const int& n, vector<int>& dp)
    {
        if(dp[i]!=-1) return dp[i];

        dp[i]=0;
        for(int j=i+minJump;j<=min(i+maxJump,n-1);j++)
        {
            if(s[j]=='0' && dfs(s,j,minJump, maxJump, n, dp))
            {
               dp[i]=1;
               break;
            }
        }
        return dp[i];
    }

};