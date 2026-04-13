class RandomizedSet {
    unordered_set<int> dp;
public:
    RandomizedSet() {
        dp.clear();
    }
    
    bool insert(int val) {
        if(dp.count(val)) return true;
        dp.insert(val);
        return false;
    }
    
    bool remove(int val) {
        if(!dp.count(val)) return false;
        dp.erase(val);
        return true;
    }
    
    int getRandom(){
        int n=dp.size();
        int i=rand()%n;
        vector<int>adj(dp.begin(),dp.end());
        return adj[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */