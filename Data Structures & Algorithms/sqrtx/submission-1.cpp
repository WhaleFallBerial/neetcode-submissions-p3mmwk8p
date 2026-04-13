class Solution {
public:
    int mySqrt(int x) {
        for(int i=1;i<x;i++)
        {
            if(1LL*i*i>x) return i-1;
        }
        return x;
    }
};