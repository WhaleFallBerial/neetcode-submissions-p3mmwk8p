class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int rows=matrix.size(), cols=matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        for(int r=0;r<rows;r++)
        {
            for(int c=0;c<cols;c++)
            {
                if(matrix[r][c])
                {
                    int tmp=0;
                    for(int i=r;i>=0;i--)
                    {
                        if(matrix[i][c])
                        {
                            tmp++;
                        }else{
                            break;
                        }
                    }
                    dp[r][c]=tmp;
                }
            }
        }
        for(int r=0;r<rows;r++)
        {
            sort(dp[r].rbegin(), dp[r].rend());
        }
        int res=0;
        for(int r=0;r<rows;r++)
        {
            for(int c=0;c<cols;c++)
            {
                res=max(res, dp[r][c]*(c+1));
            }
        }
        return res;


    }
};