class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rows=matrix[0].size();
        int cols=matrix.size();
        vector<vector<int>> res(rows, vector<int>(cols,0));
        for(int r=0;r<rows;r++)
        {
            for(int c=0;c<cols;c++)
            {
                res[r][c]=matrix[c][r];
            }

        }
        return res;
    }
};