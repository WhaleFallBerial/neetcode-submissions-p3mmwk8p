class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int colz=0;
        int rowz=0;
        for(int r=0;r<rows;r++)
        {
            for(int c=0;c<cols;c++)
            {
                if(matrix[r][c]==0)
                {
                    if(r>0)
                    {
                        matrix[0][c]=0;
                    }else{
                        rowz=true;
                    }
                    if(c>0)
                    {
                        matrix[r][0]=0;
                    }else{
                        colz=true;
                    }
                }
            }
        }
        for(int r=1;r<rows;r++)
        {
            for(int c=1;c<cols;c++)
            {
                if(matrix[0][c]==0||matrix[r][0]==0) matrix[r][c]=0;
            }
        }

        if(rowz)
        {
            for(int c=0;c<cols;c++)
            {
                matrix[0][c]=0;
            }
        }
        if(colz)
        {
            for(int r=0;r<rows;r++)
            {
                matrix[r][0]=0;
            }
        }
    }
};
