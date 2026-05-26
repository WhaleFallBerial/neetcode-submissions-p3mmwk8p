class Solution {
    int dfs(int i, int j, const string& str1, const string& str2, vector<vector<int>>& dp)
    {
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==str1.size())
        {
            dp[i][j]=str2.size()-j;
            return dp[i][j];
        }
        if(j==str2.size())
        {
            dp[i][j]=str1.size()-i;
            return dp[i][j];
        }
        if(str1[i]==str2[j])
        {
            dp[i][j]=1+dfs(i+1, j+1, str1, str2, dp);
        }else{
            dp[i][j]=1+min(dfs(i+1, j, str1, str2, dp),dfs(i, j+1, str1, str2, dp));
        }
        return dp[i][j];
    }
    string buildstr(const string& str1, const string& str2, vector<vector<int>>& dp)
    {
        string res;
        int i=0, j=0;
        while(i<str1.size()||j<str2.size())
        {
            if(i==str1.size())
            {
                res+=str2.substr(j);
                break;
            }
            if(j==str2.size())
            {
                res+=str1.substr(i);
                break;
            }
            if(str1[i]==str2[j])
            {
                res+=str1[i];
                i++;
                j++;
            }else if(dp[i+1][j]>dp[i][j+1])
            {
                res+=str2[j];
                j++;
            }else{
                res+=str1[i];
                i++;
            }
        }


        return res;
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
        dfs(0,0,str1, str2, dp);

        return buildstr(str1, str2, dp);
    }
};