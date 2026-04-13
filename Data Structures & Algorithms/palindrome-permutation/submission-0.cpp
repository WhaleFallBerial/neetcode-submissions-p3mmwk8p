class Solution {
public:
    bool canPermutePalindrome(string s) {
        int n=s.size();
        unordered_map<char, int>adj;
        bool flag=false;
        for(auto c:s)
        {
            adj[c]++;
        }
        for(auto [a,b]:adj)
        {
            if((b%2!=0)&&(!flag))
            {
                flag=true;
            } else if(b%2!=0&&flag)
            {
                return false;
            }
        }
        return true;
    }
};
