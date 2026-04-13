class Solution {
public:
    int lengthOfLastWord(string s) {
        int res=0;
        int n=s.size();
        bool flag=false;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]==' '&& flag) break;
            if(s[i]!=' ')
            {
                flag=true;
                res++;
            }
            
        }
        return res;
    }
};