class MyLinkedList {
public:
    deque<int> data;
    MyLinkedList() {
        data.clear();
    }
    
    int get(int index) {
        if(index<0||index>=data.size()) return -1;
        return data[index];
    }
    
    void addAtHead(int val) {
        data.push_front(val);
    }
    
    void addAtTail(int val) {
        data.push_back(val);
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > (int)data.size()) return;
        data.insert(data.begin() + index, val);
    }
    
    void deleteAtIndex(int index) {
        if(index<0||index>=data.size()) return;
        data.erase(data.begin()+index);
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */