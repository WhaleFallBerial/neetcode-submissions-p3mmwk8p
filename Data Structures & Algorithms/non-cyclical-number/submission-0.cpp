class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visit;
        while(!visit.count(n))
        {
            visit.insert(n);
            n=sum_of_square(n);
            if(n==1) return true;
        }
        return false;
    }
private:
    int sum_of_square(int n)
    {
        int output=0;
        while(n>0)
        {
            int digit=n%10;
            digit*=digit;
            output+=digit;
            n/=10;
        }
        return output;
    }
};
