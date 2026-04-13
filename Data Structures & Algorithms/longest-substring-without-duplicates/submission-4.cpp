class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;
        if(s.empty())
        {
            return 0;
        }
        
        for(int l=0;l<s.length();l++)
        {
            unordered_set<char> alpha;
            alpha.insert(s[l]);
            int length=1;
            for(int r=l+1;r<s.length();r++)
            {   
                if(alpha.count(s[r]))
                {
                    res=max(res,length);
                    break;
                }
                alpha.insert(s[r]);
                length++;
                res=max(res,length);
            }
            res=max(res,length);
        }
        return res;
    }
};
