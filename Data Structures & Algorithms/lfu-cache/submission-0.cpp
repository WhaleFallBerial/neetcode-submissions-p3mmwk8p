class LFUCache {
private:
    struct Node{
        int value, freq, time;
        Node(): value(0), freq(0), time(0) {}
        Node(int v,int f, int t): value(v), freq(f), time(t){ }
    };
    int capacity,time;
    unordered_map<int, Node> cache;
public:
    LFUCache(int capacity):capacity(capacity),time(0) {}
    
    int get(int key) {
        if(cache.find(key)==cache.end()) return -1;
        cache[key].freq++;
        cache[key].time=++time;
        return cache[key].value;        
    }
    
    void put(int key, int value) {
        time++;
        if(capacity==0) return;
        if(cache.find(key)!=cache.end())
        {
            cache[key].value=value;
            cache[key].time=time;
            cache[key].freq++;
            return;
        }
        if(cache.size()>=capacity)
        {
            int minfreq=INT_MAX;
            int mintime=INT_MAX;
            int lfu=-1;
            for(auto& [k,node]:cache)
            {
                if(node.freq<minfreq||(node.freq==minfreq&&node.time<mintime))
                {
                    minfreq=node.freq;
                    mintime=node.time;
                    lfu=k;
                }
            }
            cache.erase(lfu);
        }
        cache[key]=Node(value,1,time);
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */