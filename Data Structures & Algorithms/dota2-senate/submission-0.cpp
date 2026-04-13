class Solution {
public:
    string predictPartyVictory(string senate) {
        int n=senate.size();
        queue<int> r,d;
        for(int i=0;i<n;i++)
        {
            if(senate[i]=='R')
            {   
                r.push(i);
            }else if(senate[i]=='D'){
                d.push(i);
            }
        }
        while(!r.empty() && !d.empty())
        {
            int r_first=r.front();
            int d_first=d.front();
            r.pop();
            d.pop();

            if(r_first<d_first)
            {
                r.push(r_first+n);
            }else if(d_first<r_first)
            {
                d.push(d_first+n);
            }
        }
        return r.empty()? "Dire":"Radiant";
    }
};