class Solution {
public:
    int scoreOfString(string s) {
        int len=s.size();
        int res=0;
        for(int i=0;i<len-1;i++)
        {
            res+=(abs(s[i+1]-s[i]));          
        }
        return res;
    }
};