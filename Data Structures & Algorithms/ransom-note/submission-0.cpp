class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> adj;
        for(auto m:magazine)
        {
            adj[m]++;
        }
        for(auto r:ransomNote)
        {
            adj[r]--;
            if(adj[r]<0) return false;
        }
        return true;
    }
};