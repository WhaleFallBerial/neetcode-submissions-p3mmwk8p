class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> res(n+1);
        res[0]={""};

        for(int i=0;i<=n;i++)
        {
            for(int k=0;k<i;k++)
            {
                for(const string& left: res[k])
                {
                    for(const string& right: res[i-k-1])
                    {
                        res[i].push_back("("+left+")"+right);
                    }
                }
            }
        }
        return res[n];

    }
};
