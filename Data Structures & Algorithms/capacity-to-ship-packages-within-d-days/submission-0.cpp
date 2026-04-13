class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int res=*max_element(weights.begin(),weights.end());
        while(true)
        {
            int ship=1;
            int cap=res;
            for(auto& w:weights)
            {
                if(cap-w<0)
                {
                    ship++;
                    cap=res;
                }
                cap-=w;
            }
            if(ship<=days) return res;
            res++;
        }

    }

};