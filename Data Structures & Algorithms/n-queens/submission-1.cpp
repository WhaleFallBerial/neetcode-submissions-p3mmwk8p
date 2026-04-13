class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n,string(n,'.'));
        dfs(board,res,0,n);
        return res;
    }

    void dfs(vector<string>& board, vector<vector<string>>& res, int r, int n)
    {
        if(r==n)
        {
            res.push_back(board);
            return;
        }

        for(int c=0;c<n;c++)
        {
            if(safe(board,r,c,n))
            {
                board[r][c]='Q';
                dfs(board,res,r+1,n);
                board[r][c]='.';
            }

        }
    }

    bool safe(vector<string>& board, int r, int c, int n)
    {
        for(int i=r-1;i>=0;i--)
        {
            if(board[i][c]=='Q') return false;
        }
        for(int i=r-1,j=c-1;i>=0&&j>=0;i--,j--)
        {
            if(board[i][j]=='Q') return false;
        }
        for(int i=r-1,j=c+1;i>=0&&j<n;i--,j++)
        {
            if(board[i][j]=='Q') return false;
        }
        return true;
    }
};
