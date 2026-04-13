class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>lastw;
        for(auto i=0;i<s.size();i++)
        {
            lastw[s[i]]=i;
        }
        vector<int> res;
        int endw=0;
        int size=0;
        for(int i=0;i<s.size();i++)
        {
            size++;
            endw=max(endw, lastw[s[i]]);
            if(i==endw) 
            {
                res.push_back(size);
                size=0;

            }
        }
        return res;
    }
};
