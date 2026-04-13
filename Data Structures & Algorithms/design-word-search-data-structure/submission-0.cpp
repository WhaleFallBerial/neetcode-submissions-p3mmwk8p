class WordDictionary {
    vector<string> store;
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        store.push_back(word);
    }
    
    bool search(string word) {

        for(auto w:store)
        {
            if(w.size()!=word.size()) continue;
            int i=0;
            while(i<word.size())
            {
                if(w[i]==word[i]||word[i]=='.')
                {
                    i++;
                }else{
                    break;
                }
            }
            if(i==word.size()) return true;
        }        
        return false;
    }
};
