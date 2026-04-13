class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res=right;
        while(left<res)
        {
            res&=(res-1);
        }
        return res;
    }
};