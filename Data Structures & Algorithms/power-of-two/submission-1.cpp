class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0) return false;
        int tmp=0;
        while(n!=1&&tmp==0)
        {
            tmp=n%2;
            n/=2;
            if(tmp!=0) return false;
        }
        if(n==1)
            return true;
        else
            return false;
    }
};