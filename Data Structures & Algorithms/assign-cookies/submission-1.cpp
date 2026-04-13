class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int index=0;
        int res=0;
        for(auto c:g)
        {
            for(int i=index;i<s.size();i++)
            {
                if(c<=s[i]) 
                {
                    index=i+1;
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};