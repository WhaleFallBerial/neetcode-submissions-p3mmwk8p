class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n=s.size();
        int one_cnt=0;
        for(auto c:s)
        {
            if(c=='1')
            {
                one_cnt++;
            }
        }
        string res;
        for(int i=1;i<one_cnt;i++)
        {
            res+='1';
        }
        for(int i=1;i<=n-one_cnt;i++)
        {
            res+='0';
        }
        if(one_cnt>0)
        {
            res+='1';
        }
        return res;
    }
};