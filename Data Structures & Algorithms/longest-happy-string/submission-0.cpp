class Solution {
    int get_max(vector<int>& v, int repeated)
    {
        int index=-1;
        int maxc=0;
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            if(i==repeated||v[i]==0) continue;
            if(maxc<v[i])
            {
                maxc=v[i];
                index=i;
            }
        }
        return index;
    }
public:
    string longestDiverseString(int a, int b, int c) {
        vector<int>v={a,b,c};
        string res;
        int repeated=-1;
        while(true)
        {
            int maxc=get_max(v,repeated);
            if(maxc==-1) break;
            res+=(char)(maxc+'a');
            v[maxc]--;
            if(res.size()>1&&(res[res.size()-1]==res[res.size()-2]))
            {
                repeated=maxc;
            }else{
                repeated=-1;
            }
        }
        return res;
    }
};