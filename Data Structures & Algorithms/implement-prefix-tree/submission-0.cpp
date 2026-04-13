class TrieNode {
public:
    unordered_map<char,TrieNode*> child;
    int end_of_word=false;
};

class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur=root;
        for(auto c: word)
        {
            if(cur->child.find(c)==cur->child.end())
            {
                cur->child[c]=new TrieNode();
            }
            cur=cur->child[c];
        }
        cur->end_of_word=true;
    }
    
    bool search(string word) {
        TrieNode* cur=root;
        for(auto c:word)
        {
            if(cur->child.find(c)==cur->child.end())
            {
                return false;
            }
        cur=cur->child[c];
        }
        return cur->end_of_word;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur=root;
        for(auto c:prefix)
        {
            if(cur->child.find(c)==cur->child.end())
            {
                return false;
            }
        cur=cur->child[c];
        }
        return true;
    }
};
