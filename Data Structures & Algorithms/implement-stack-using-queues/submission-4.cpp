class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        data.push(x);
    }
    
    int pop() {
        queue<int> tmp=data;
        int n=data.size();
        data=queue<int>();
        for(int i=0;i<n-1;i++)
        {
            data.push(tmp.front());
            tmp.pop();
        }
        return tmp.front();
    }
    
    int top() {
        queue<int> tmp=data;
        for(int i=0;i<data.size()-1;i++)
        {
            tmp.pop();
        }
        return tmp.front();
    }
    
    bool empty() {
       return data.empty();
    }
private:
    queue<int> data;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */