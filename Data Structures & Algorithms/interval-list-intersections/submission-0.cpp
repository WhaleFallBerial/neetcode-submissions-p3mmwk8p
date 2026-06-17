class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int fn=firstList.size();
        int sn=secondList.size();
        if(!fn||!sn)
        {
            return {};
        }
        vector<vector<int>> res;
        int i=0, j=0;
        while(i<fn&&j<sn)
        {
            int fstart=firstList[i][0], fend=firstList[i][1];
            int sstart=secondList[j][0], send=secondList[j][1];
            if(fstart>send)
            {
                j++;
            }else if(sstart>fend)
            {
                i++;
            }else{
                int a=max(fstart, sstart);
                int b=min(fend, send);
                res.push_back({a,b});
                if(send<fend)
                {
                    j++;
                }else{
                    i++;
                }
            }
        }

        return res;
    }
};