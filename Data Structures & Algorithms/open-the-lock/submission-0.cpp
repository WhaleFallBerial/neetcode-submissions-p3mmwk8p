class Solution {
    vector<string> get_next_string(string original)
    {
        vector<string> result;

        for(int i=0;i<original.size();i++)
        {
            int digit=0;
            digit=original[i]-'0';
            string next=original;
            next[i]='0'+(digit+1)%10;
            result.push_back(next);
            string down=original;
            down[i]='0'+(digit+9)%10;
            result.push_back(down);
        }
        return result;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> visited;
        for(auto& d:deadends)
        {
            visited.insert(d);
        }
        if(visited.count("0000")) return -1;
        if(target=="0000") return 0;
        queue<string> q;
        q.push("0000");
        int step=0;
        while(!q.empty())
        {
            step++;
            int qsize=q.size();
            for(int i=0;i<qsize;i++)
            {
                string curr=q.front();
                q.pop();
                vector<string> next_string;
                next_string=get_next_string(curr);
                for(auto& n:next_string)
                {
                    if(n==target) return step;
                    if(!visited.count(n))
                    {
                        q.push(n);
                        visited.insert(n);
                    }
                }

            }
        }
        return -1;
    }
};