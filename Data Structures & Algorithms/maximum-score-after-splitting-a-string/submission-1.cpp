class Solution {
public:
    int maxScore(string s) {
        int zcnt=0, ocnt=0, n=s.size();
        for(auto c:s)
        {
            if(c=='1')
            {
                ocnt++;
            }
        }
        int res=INT_MIN;
        for(int i=0;i<n-1;i++)
        {

            if(s[i]=='0')
            {
                zcnt++;
            }else{
                ocnt--;
            }
            res=max(res,ocnt+zcnt);
        }
        return res;
    }
};