class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> res;
        int twice_a=0;
        int miss_b=0;
        int n=grid.size();
        unordered_set<int> adj;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(adj.count(grid[i][j]))
                {
                    twice_a=grid[i][j];
                }else{
                    adj.insert(grid[i][j]);
                }
            }
        }
        for(int i=1;i<=n*n;i++)
        {
            if(!adj.count(i))
            {
                miss_b=i;
            }
        }
        res.push_back(twice_a);
         res.push_back(miss_b);
        return res;
    }
};