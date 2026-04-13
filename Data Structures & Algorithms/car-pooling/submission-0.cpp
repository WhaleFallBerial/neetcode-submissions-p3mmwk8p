class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
       int l=INT_MAX;
       int r=INT_MIN;
       for(auto& t:trips)
       {
        l=min(l,t[1]);
        r=max(r,t[2]);
       } 
       int n=r-l+1;
       vector<int> change(n+1,0);
       for(auto& t:trips)
       {
        change[t[1]-l]+=t[0];
        change[t[2]-l]-=t[0];
       }
       int cur=0;
       for(auto& c:change)
       {
        cur+=c;
        if(cur>capacity) return false;
       }
       return true;
    }
};