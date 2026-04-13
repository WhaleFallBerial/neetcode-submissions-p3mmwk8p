class Solution {
public:
    int arrangeCoins(int n) {
        unsigned long tmp=0;
        int res=1;
        for(int i=1;i<n;i++)
        {
            tmp+=i;
            if(tmp>n)
            {
                res=i-1;
                break;
            }
        }
        return res;
    }
};