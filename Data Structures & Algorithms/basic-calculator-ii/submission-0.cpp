class Solution {
public:
    int calculate(string s) {
        int n=s.size();
        int index=0;
        int tmp=0;
        int pre=0;
        char op='+';
        vector<int> dp;
            for(int i=0;i<s.size();i++)
            {

                if(isdigit(s[i])&&i!=n-1)
                {
                  tmp=tmp*10+(s[i]-'0');
                }else if(i==n-1){
                    if(isdigit(s[i]))
                       tmp=tmp*10+(s[i]-'0');
                    if(op=='+')
                    {
                        dp.push_back(tmp);
                    }else if(op=='-')
                    {
                        dp.push_back(-tmp);
                    }else if(op=='*')
                    {
                        pre=dp.back();
                        dp.pop_back();
                        int cun=pre*tmp;
                        dp.push_back(cun);
                    }else if(op=='/')
                    {
                        pre=dp.back();
                        dp.pop_back();
                        int cun=pre/tmp;
                        dp.push_back(cun);
                    }
                }else if(s[i]==' ')
                {
                    continue;
                }else if(!isdigit(s[i])){
                    
                    
                    if(op=='+')
                    {
                        dp.push_back(tmp);
                    }else if(op=='-')
                    {
                        dp.push_back(-tmp);
                    }else if(op=='*')
                    {
                        pre=dp.back();
                        dp.pop_back();
                        int cun=pre*tmp;
                        dp.push_back(cun);
                    }else if(op=='/')
                    {
                        pre=dp.back();
                        dp.pop_back();
                        int cun=pre/tmp;
                        dp.push_back(cun);
                    }
                    tmp=0;
                    op=s[i];
                }
            }
            int res=accumulate(dp.begin(),dp.end(),0);
            return res;
    }
};