class Solution {
public:
    bool checkValidString(string s) {
        mem.assign(s.size()+1,vector<int>(s.size()+1, -1));
        return dfs(0,0,s);
    }
private:
    vector<vector<int>> mem;
    int dfs(int i, int open, string& s)
    {
        if(open<0) return false;
        if(i==s.size()) return open==0;

        int res=0;
        if(s[i]=='(')
        {
            res=dfs(i+1,open+1,s);
        }else if(s[i]==')')
        {
            res=dfs(i+1,open-1,s);
        }else{
            res=dfs(i+1,open,s)||dfs(i+1,open+1,s)||dfs(i+1,open-1,s);
        }
        mem[i][open]=res;
        return res;
    }
};
