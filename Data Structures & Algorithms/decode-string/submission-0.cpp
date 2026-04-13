class Solution {
public:
    string decodeString(string s) {
        vector<int> istack;
        vector<string> cstack;
        int k=0;
        string cur="";
        for(auto& c:s)
        {
            if(isdigit(c))
            {
                k=k*10+(c-'0');
            }else if(c=='[')
            {
                istack.push_back(k);
                cstack.push_back(cur);
                k=0;
                cur.clear();
            }else if(c==']')
            {
                string tmp=cur;
                cur=cstack.back();
                cstack.pop_back();
                int count=istack.back();
                istack.pop_back();
                for(int i=0;i<count;i++)
                {
                    cur+=tmp;
                }
            }else{
                cur+=c;
            }
        }
        return cur;
    }
};