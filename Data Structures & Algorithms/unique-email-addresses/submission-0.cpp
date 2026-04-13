class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> adj;
        int n=emails.size();
        for(int i=0;i<n;i++)
        {
            bool flag=false;
            string tmp_str;
            for(int j=0;j<emails[i].size();j++)
            {
                if(!flag)
                {
                    if(emails[i][j]=='+')
                    {
                        flag=true;
                        continue;
                    }else if(emails[i][j]=='.')
                    {
                        continue;
                    }
                    tmp_str+=emails[i][j];
                }else{
                    if(emails[i][j]=='@')
                    {
                        flag=false;
                        tmp_str+=emails[i].substr(j);
                    }
                }
            }
            if(!adj.count(tmp_str))
            {
                adj.insert(tmp_str);
            }
        }
        return adj.size();

    }
};