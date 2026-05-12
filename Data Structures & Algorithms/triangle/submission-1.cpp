class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        for(int level=n-2;level>=0;level--)
        {
            for(int idx=0;idx<triangle[level].size();idx++)
            {
                triangle[level][idx]+=min(triangle[level+1][idx],triangle[level+1][idx+1]);
            }
        }
        return triangle[0][0];
    }
};