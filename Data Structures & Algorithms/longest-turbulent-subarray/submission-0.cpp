class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        int maxlen=1;
        for(int i=0;i<n;i++){
            maxlen=max(maxlen, dfs(arr,n,dp,i,true));
            maxlen=max(maxlen, dfs(arr,n,dp,i,false));
        }
        return maxlen;
    }

    int dfs(const vector<int>& arr, const int& n, vector<vector<int>>& dp,const int i,const bool larger)
    {
        if(dp[i][larger]!=-1)
        {
            return dp[i][larger];
        }
        if(i==n-1) 
        {
            return 1;
        }
        int res=1;
        if((larger&&arr[i]>arr[i+1])
        ||(!larger&&arr[i]<arr[i+1]))
        {
            res+=dfs(arr, n, dp, i+1, !larger);
        }
        dp[i][larger]=res;
        
        return dp[i][larger];
    }
};