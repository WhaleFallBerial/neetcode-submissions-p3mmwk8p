class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        for(auto i=0;i<points.size()-1;i++)
        {
            for(auto j=0;j<points.size()-1-i;j++)
        {
            if(points[j][0]*points[j][0]+points[j][1]*points[j][1]>
            points[j+1][0]*points[j+1][0]+points[j+1][1]*points[j+1][1])
            {
                swap(points[j],points[j+1]);
                }
        }
        }
        return vector<vector<int>>(points.begin(),points.begin()+k);
        
    }
};
