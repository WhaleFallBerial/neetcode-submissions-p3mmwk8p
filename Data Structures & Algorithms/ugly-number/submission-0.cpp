class Solution {
public:
    bool isUgly(int n) {
        int tmp=n;
        int res=true;
        while(tmp!=1)
        {
            if(tmp%2!=0 && tmp%3!=0 && tmp%5!=0)
            {
                res=false;
                break;
            }

            if(tmp%2==0)
            {
                tmp/=2;
            }
            if(tmp%3==0)
            {
                tmp/=3;
            }
            if(tmp%5==0)
            {
                tmp/=5;
            }
        }

        return res;
    }
};