class Solution {
public:
    bool isPalindrome(int x) {
        string str=to_string(x);
        int r=str.size()-1,l=0;

        while(l<r)
        {
            if(str[r]!=str[l])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};