class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        capacity=k;
    }
    
    bool enQueue(int value) {
         if(data.size()<capacity)
        {
            data.push_back(value);
            return true;
        }else{
            return false;
        }
    }
    
    bool deQueue() {
        if(!data.empty())
        {
            data.erase(data.begin());
            return true;
        }else{
            return false;
        }
    }
    
    int Front() {
        if(data.empty()) return -1;
        return data.front();
    }
    
    int Rear() {
        if(data.empty()) return -1;
        return data.back();
    }
    
    bool isEmpty() {
        return data.empty();
    }
    
    bool isFull() {
        return data.size()==capacity;
    }
private:
    vector<int> data;
    int capacity;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */