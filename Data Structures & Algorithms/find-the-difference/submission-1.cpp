class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_set<char> adj;
        for(auto c:s)
        {   if(adj.count(c))
            {
                adj.erase(c);
            }else{
                adj.insert(c);
            }
        }
        for(auto c:t)
        {
            if(adj.count(c))
            {
                adj.erase(c);
            }else{
                adj.insert(c);
            }
        }
        return *adj.begin();
    }
};