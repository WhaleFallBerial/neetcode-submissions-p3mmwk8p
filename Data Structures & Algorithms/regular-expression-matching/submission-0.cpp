class Solution {
public:
    bool isMatch(string s, string p) {
        mem.assign(s.size()+1,vector<int>(p.size()+1, -1));
        return dfs(s,p,0,0);
    }
private:
vector<vector<int>> mem;
bool dfs(string& s, string& p, int i, int j)
{
    if(j==p.size()) return i==s.size();
    if(mem[i][j]!=-1) return mem[i][j];
    bool match=i<s.size()&&j<p.size()&&(s[i]==p[j]||p[j]=='.');
    if(j+1<p.size()&&p[j+1]=='*')
    {
        return mem[i][j]=dfs(s,p,i,j+2)||(match&&dfs(s,p,i+1,j));
    }
    if(match)
    {
        return mem[i][j]=dfs(s,p,i+1,j+1);
    }
    return false;
}
};
