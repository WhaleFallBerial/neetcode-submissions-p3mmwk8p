class TrieNode{
public:
unordered_map<char,TrieNode*> child;
bool isWord;

TrieNode():isWord(false){}
void addWord(const string& str)
{
    TrieNode* cur=this;
    for(auto & w:str)
    {
        if(!cur->child.count(w))
        {
            cur->child[w]=new TrieNode();
            
        }
        cur=cur->child[w];
    }
    cur->isWord=true;
}

};


class Solution {
public:
    unordered_set<string> res;
    vector<vector<int>> visit;
    int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root=new TrieNode();
        for(auto& w:words)
        {
            root->addWord(w);
        }
        int rows=board.size(),cols=board[0].size();
        visit.assign(rows,vector<int>(cols,false));
        for(int r=0;r<rows;r++)
        {
            for(int c=0;c<cols;c++)
            {
                dfs(board,r,c,root,rows,cols,"");
            }
        }
        return vector<string>(res.begin(),res.end());
    }

private:
   void dfs(vector<vector<char>>& board,int r,int c, TrieNode* node,int& rows,int& cols,string str)
   {
        if(r>=rows||c>=cols||r<0||c<0||visit[r][c]||!node->child.count(board[r][c])) return;

        visit[r][c]=true;
        node=node->child[board[r][c]];
        str+=board[r][c];
        if(node->isWord) res.insert(str);

        for(int i=0;i<4;i++)
        {
            dfs(board,r+d[i][0],c+d[i][1],node,rows,cols,str);
        }
        visit[r][c]=false;

   }
};