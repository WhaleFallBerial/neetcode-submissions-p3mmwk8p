class Solution {
public:
    int numDistinct(string s, string t) {
        if(t.size()>s.size()) return false;
        mem.assign(s.size()+1,vector<int>(t.size()+1,-1));
        return dfs(s,t,0,0);
    }
private:
    vector<vector<int>> mem;
    int dfs(string& s, string& t, int i, int j)
    {   if(j==t.size()) return 1;
        if(i==s.size()) return 0;
        if(mem[i][j]!=-1) return mem[i][j];
        int res=dfs(s,t,i+1,j);
        if(s[i]==t[j]) res+=dfs(s,t,i+1,j+1);
        mem[i][j]=res;
        return mem[i][j];
    }
};
