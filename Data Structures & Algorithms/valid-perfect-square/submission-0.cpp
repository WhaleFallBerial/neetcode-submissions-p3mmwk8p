class Solution {
public:
    bool isPerfectSquare(int num) {
        for(int i=1;i<=num;i++)
        {
            if(i==(num/i)&&(num%i)==0)
                return true;
        }
        return false;
    }
};