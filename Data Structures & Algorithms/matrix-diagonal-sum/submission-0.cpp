class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int res=0;
        for(int i=0;i<n;i++)
        {
            res+=mat[i][i];
        }
        for(int i=0;i<n;i++)
        {
            int r=n-i-1;
            int c=i;
            if(c!=r)
            {
                res+=mat[r][c];
            }
        }
        return res;
    }
};