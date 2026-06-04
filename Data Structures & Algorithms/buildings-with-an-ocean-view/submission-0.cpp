class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n=heights.size();
        vector<int> res;
        int tmp_h=INT_MIN;
        for(int i=n-1;i>=0;i--)
        {
            if(heights[i]>tmp_h)
            {
                res.push_back(i);
                tmp_h=heights[i];
            }

        }
        reverse(res.begin(), res.end());
        return res;
    }
};