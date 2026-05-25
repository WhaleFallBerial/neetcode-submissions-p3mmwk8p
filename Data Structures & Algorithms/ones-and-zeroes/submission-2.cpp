class Solution {
    int dfs(int m, int n, int i , vector<vector<int>>& dp, vector<vector<vector<int>>>& mem)
    {
        if(i>=dp.size()) return 0;

        if(m==0&&n==0) return 0;

        if(mem[i][m][n]!=-1) return mem[i][m][n];



        int res=dfs(m, n, i+1, dp, mem);
        if(m>=dp[i][0]&&n>=dp[i][1])
        {
            res=max(res, 1+dfs(m-dp[i][0], n-dp[i][1], i+1, dp, mem));
        }

        mem[i][m][n]=res;
        return res;

    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int num=strs.size();
        vector<vector<int>>dp(num, vector<int>(2,0));
        vector<vector<vector<int>>> mem(num, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        for(int i=0;i<num;i++)
        {
            for(int j=0;j<strs[i].size();j++)
            {
                if(strs[i][j]=='0')
                {
                    dp[i][0]++;
                }else{
                    dp[i][1]++;
                }
            }
        }

        return dfs(m, n, 0, dp, mem);
    }
};