class Solution {
public:
    string simplifyPath(string path) {
        string res="/";
        vector<string> data;
        string cur;
        string tmp=path+"/";
        for(auto& c: tmp)
        {
            if(c=='/')
            {
                if(cur=="..")
                {
                    if(!data.empty()) data.pop_back();
                    cur="";
                }else if(cur.empty()||cur==".")
                {
                    cur="";
                }else{
                    data.push_back(cur);
                    cur="";
                }
            }else{
                cur+=c;
            }  
        }
        for(int i=0;i<data.size();i++)
        {
            if(i>0) res+="/";
            res+=data[i];
        }
        return res;

    }
};