class Solution {
public:
    int appendCharacters(string s, string t) {
        int ns=s.size();
        int nt=t.size();

        int cnt=0;
        int res=0;
        for(int i=0;i<ns;i++)
        {
            if(s[i]==t[cnt])
            {
                cnt++;
            }
        }

        if(cnt<nt)
        {
            res+=(nt-cnt);
        }
        return res;
    }
};