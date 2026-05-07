class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=pref.size();
        int res=0;
        for(auto w:words)
        {
            if(w.size()<n) continue;
            bool flag=true;
            for(int i=0;i<n;i++)
            {
                if(pref[i]!=w[i])
                {
                    flag=false;
                    break;
                }
                    
            }
            if(flag) res++;
        }
        return res;
    }
};