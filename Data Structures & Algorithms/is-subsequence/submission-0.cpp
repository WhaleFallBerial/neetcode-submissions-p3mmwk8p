class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ns=s.size();
        int nt=t.size();

        int cnt=0;
        for(int i=0;i<nt;i++)
        {
           

            if(t[i]==s[cnt])
            {
                cnt++;
            }
             if(cnt==ns) return true;
        }
        return false;
    }
};