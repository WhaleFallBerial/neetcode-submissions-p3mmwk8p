class Solution {
public:
    int uniquePaths(int m, int n) {
        return dfs(m,n,0,0);
    }
    int dfs(int m, int n, int r, int c)
    {
        if(r>=m||r<0||c>=n||c<0) return 0;
        if(r==(m-1)&&c==(n-1)) return 1;

        return dfs(m,n,r+1,c)+dfs(m,n,r,c+1);
    }
};
