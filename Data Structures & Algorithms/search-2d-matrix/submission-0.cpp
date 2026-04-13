class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size(), col=matrix[0].size();
        int init=0;
        int end=row*col-1;
        while(init<=end)
        {
            int m=init+(end-init)/2;
            int r=m/col,c=m%col;
            if(matrix[r][c]>target)
            {
                end=m-1;
            }else if(matrix[r][c]<target)
            {
                init=m+1;
            }else{
                return true;
            }
        }
        return false;
    }
};
