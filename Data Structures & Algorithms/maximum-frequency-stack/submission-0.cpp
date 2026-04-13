class FreqStack {
public:
    FreqStack() {
        data.clear();
        freq.clear();
    }
    
    void push(int val) {
        data.push_back(val);
        freq[val]++;
    }
    
    int pop() {
        int maxv=INT_MIN;
        for(auto& f:freq)
        {
            maxv=max(maxv,f.second);
        }
        int n=data.size();
        int res;
        for(int i=n-1;i>=0;i--)
        {
            if(freq[data[i]]==maxv)
            {
                res=data[i];
                freq[data[i]]--;
                data.erase(data.begin()+i);
                break;
            } 
        }
        
        
        
        return res;

    }
private:
    vector<int> data;
    unordered_map<int, int> freq;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */