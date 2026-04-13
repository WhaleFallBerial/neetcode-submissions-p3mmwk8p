class Solution {
public:
    int totalNQueens(int n) {
        int res=0;
        vector<string> board(n,".");
        dfs(0,board,res);
        return res;
    }
    void dfs(int r, vector<string>& board, int& res)
    {
        if(r==board.size())
        {
            res++;
            return;
        }

        for(int c=0;c<board.size();c++)
        {
            if(is_safe(r,c,board))
            {
                board[r][c]='Q';
                dfs(r+1,board,res);
                board[r][c]='.';
            }
        }

    }
    bool is_safe(int r,int c, vector<string>& board)
    {
        for(int i=r-1;i>=0;i--)
        {
            if(board[i][c]=='Q') return false;
        }
        for(int i=r-1, j=c-1;i>=0&&j>=0;i--,j--)
        {
            if(board[i][j]=='Q') return false;
        }
        for(int i=r-1, j=c+1;i>=0&&j<board.size();i--,j++)
        {
            if(board[i][j]=='Q') return false;
        }
        return true;
    }

};
