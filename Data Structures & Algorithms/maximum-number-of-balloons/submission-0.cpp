class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> w;
        for(auto t:text)
        {
            w[t]++;
        }
        int res=INT_MAX;
        res=min(res,w['b']/1);
        res=min(res,w['a']/1);
        res=min(res,w['l']/2);
        res=min(res,w['o']/2);
        res=min(res,w['n']/1);
        return res;
    }
};