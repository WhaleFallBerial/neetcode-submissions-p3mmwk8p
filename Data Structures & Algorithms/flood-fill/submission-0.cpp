class Solution {
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int original_color, int nr, int nc)
    {
        if(image[sr][sc]!=original_color) return;

        
        image[sr][sc]=color;
        if(sr!=0)
        {
            dfs(image, sr-1,sc,color,original_color, nr, nc);
        }
        if(sr!=nr-1)
        {  
            dfs(image, sr+1,sc,color,original_color, nr, nc);
        }
        if(sc!=0)
        {
            dfs(image, sr,sc-1,color,original_color, nr, nc);
        }
        if(sc!=nc-1)
        {  
            dfs(image, sr,sc+1,color,original_color, nr, nc);
        }

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int nr=image.size();
        int nc=image[0].size();
        if(image[sr][sc]==color) return image;
        dfs(image, sr,sc, color, image[sr][sc], nr, nc);
        return image;
    }
};