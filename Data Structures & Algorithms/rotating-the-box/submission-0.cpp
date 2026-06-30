class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int row=boxGrid.size();
        int col=boxGrid[0].size();
        vector<vector<char>> res(col, vector<char>(row,'.'));
        for(int r=0;r<row;r++)
        {
            int stone_cnt=0;
            for(int c=0;c<col;c++)
            {
                if(boxGrid[r][c]=='*')
                {
                    res[c][row-1-r]='*';
                    for(int i=1;i<=stone_cnt;i++)
                    {
                        res[c-i][row-1-r]='#';
                    }
                    stone_cnt=0;
                }else if(boxGrid[r][c]=='#')
                {
                    stone_cnt++;
                }else{
                    //nothing
                }
            }
            if(stone_cnt!=0)
            {
                for(int i=1;i<=stone_cnt;i++)
                {
                    res[col-i][row-1-r]='#';
                }
            }
        }
        return res;
    }
};