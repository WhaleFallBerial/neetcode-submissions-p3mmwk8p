class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        data.push(x);
    }
    
    int pop() {
        stack<int> tmp;
        int res=0;
        int n=data.size();
        
        for(int i=0;i<n-1;i++)
        {
            tmp.push(data.top());
            data.pop();
        }
        res=data.top();
        data=stack<int>();
        n=tmp.size();;
        for(int i=0;i<n;i++)
        {
            data.push(tmp.top());
            tmp.pop();
        }
        return res;

    }
    
    int peek() {
        stack<int> tmp=data;
        int n=data.size();
        int res=0;
        for(int i=0;i<n-1;i++)
        {
            tmp.pop();
        }
        res=tmp.top();
        return res;
    }
    
    bool empty() {
        return data.empty();
    }
private:
    stack<int> data;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */