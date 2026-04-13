class Solution {
public:
    int minDistance(string word1, string word2) {
        mem.assign(word1.size()+1,vector<int>(word2.size()+1,-1));
        return dfs(word1,word2, 0, 0);
    }
private:
    vector<vector<int>> mem;
    int dfs(string& word1,string& word2, int i, int j)
    {
        if(i==word1.size()) return word2.size()-j;
        if(j==word2.size()) return word1.size()-i;
        if(mem[i][j]!=-1) return mem[i][j];
        if(word1[i]==word2[j])
        {
            mem[i][j]=dfs(word1,word2,i+1,j+1);
        }else{
            int res=min(1+dfs(word1,word2,i+1,j),1+dfs(word1,word2,i,j+1));
            res=min(res,1+dfs(word1,word2,i+1,j+1));
            mem[i][j]=res;
        }
        return mem[i][j];
    }
};
