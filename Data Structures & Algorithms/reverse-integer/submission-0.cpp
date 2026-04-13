class Solution {
public:
    int reverse(int x) {
        int org=x;
        x=abs(x);
        string str=to_string(x);
        std::reverse(str.begin(),str.end());
        long long y=stoll(str);
        if(org<0) y*=-1;
        if(y>INT_MAX||y<INT_MIN) return 0;
        return static_cast<int>(y);
    }
};
