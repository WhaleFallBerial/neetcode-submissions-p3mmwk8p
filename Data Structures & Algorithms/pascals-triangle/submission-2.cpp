class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        if(numRows==0) return {};
        res[0].push_back(1);
        if(numRows==1) return res;
        for(int r=1;r<numRows;r++)
        {
            res[r].resize(r+1);
            res[r][0]=1;
            res[r][r]=1;
            for(int c=1;c<r;c++)
            {
                res[r][c]=res[r-1][c-1]+res[r-1][c];
            }
        }
        return res;

    }
};