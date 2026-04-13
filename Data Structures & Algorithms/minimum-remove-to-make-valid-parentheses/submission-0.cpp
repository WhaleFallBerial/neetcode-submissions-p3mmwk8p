class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size();
        int l=0;
        int r=n-1;
        string tmp,res;
        int flag=0;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                flag++;
                tmp+=s[i];
            }else if(s[i]==')')
            {
                if(flag>0)
                {
                    flag--;
                    tmp+=s[i];
                }
                
            }else{
                tmp+=s[i];
            }
        }
        int t=tmp.size();
        if(flag>0)
        {
            for(int i=t-1;i>=0;i--)
            {
                if(flag>0&&tmp[i]=='(')
                {
                    flag--;
                }else{
                    res=tmp[i]+res;
                }
                
            }
        }else{
            res=tmp;
        }
        return res;
    }
};
