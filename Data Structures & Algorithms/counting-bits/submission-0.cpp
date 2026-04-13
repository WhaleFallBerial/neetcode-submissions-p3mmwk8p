class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0;i<=n;i++)
        {
            int j=i;
            int output=0;
            while(j>0)
            {
                output+=j&1;
                j>>=1;
            }   
            res.push_back(output);
        }
        return res;
    }
};
