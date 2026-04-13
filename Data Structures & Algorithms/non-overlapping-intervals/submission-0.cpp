class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int prev=intervals[0][1];
        int res=0;
        for(int i=1;i<intervals.size();i++)
        {
            if(prev<=intervals[i][0])
            {
                prev=intervals[i][1];
            }else{
                res++;
                prev=min(prev,intervals[i][1]);
            }
        }
        return res;
    }
};
