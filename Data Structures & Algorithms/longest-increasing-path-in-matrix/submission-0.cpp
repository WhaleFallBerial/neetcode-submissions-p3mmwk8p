class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rows=matrix.size();
        cols=matrix[0].size();
        mem.assign(rows,vector<int>(cols,-1));
        int res=1;
        for(int r=0;r<rows;r++)
        {
            for(int c=0;c<cols;c++)
            {
                res=max(res,dfs(r,c,INT_MIN, matrix));
            }
        }
        return res;
    }
private:
    vector<vector<int>> direct={{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> mem;
    int cols=0, rows=0;
    int dfs(int r, int c,int prev, vector<vector<int>>& matrix)
    {
        if(r<0||r>=rows||c<0||c>=cols||prev>=matrix[r][c]) return 0;
        if(mem[r][c]!=-1) return mem[r][c];
        int res=1;
        for(auto& d:direct)
        {
            res=max(res,1+dfs(r+d[0],c+d[1],matrix[r][c],matrix));
        }
        mem[r][c]=res;
        return mem[r][c];
    }
};
