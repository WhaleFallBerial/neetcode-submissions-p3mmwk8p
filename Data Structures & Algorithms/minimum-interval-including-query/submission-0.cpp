class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> res;
        for(auto& q:queries)
        {
            int cur=-1;
            for(auto& i:intervals)
            {
                if(i[0]<=q&&i[1]>=q)
                {
                    if(cur==-1||cur>i[1]-i[0]+1) cur=i[1]-i[0]+1;
                }
            }
            res.push_back(cur);
        }
        return res;
    }
};
