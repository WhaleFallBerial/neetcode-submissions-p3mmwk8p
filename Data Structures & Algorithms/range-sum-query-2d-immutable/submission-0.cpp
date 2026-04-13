class NumMatrix {
public:
    vector<vector<int>> sumM;
    NumMatrix(vector<vector<int>>& matrix) {
        int rows=matrix.size(), cols=matrix[0].size();
        sumM.assign(rows+1,vector<int>(cols+1,0));
        for(int r=0;r<rows;r++)
        {
            int prev=0;
            for(int c=0;c<cols;c++)
            {
                prev+=matrix[r][c];
                sumM[r+1][c+1]=prev+sumM[r][c+1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sumM[row2+1][col2+1]-sumM[row2+1][col1]-sumM[row1][col2+1]+sumM[row1][col1];        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */