class Solution {
public:
    vector<string> letterCombinations(string digits) {
     if (digits.empty()) return {};

        vector<string> res = {""};
        vector<string> digitToChar = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "qprs", "tuv", "wxyz"
        };

        for(char digit:digits)
        {
            vector<string> tmp;
            for(auto str:res)
            {
                for(char c:digitToChar[(digit)-'0'])
                {
                    tmp.push_back(str+c);
                }
            }
            res=tmp;
        }
        return res;


    }
};
