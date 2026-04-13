class DynamicArray {
public:
    int *dynamic_array;
    int length;
    int capacity;
    DynamicArray(int capacity) :
    capacity(capacity),
    length(0){
    dynamic_array=new int[capacity];    
    }
    
    int get(int i) {
        return dynamic_array[i];
    }

    void set(int i, int n) {
        dynamic_array[i]=n;
    }

    void pushback(int n) {
        if(length==capacity)
        {
            resize();
        }

        dynamic_array[length]=n;
        length++;
    }

    int popback() {
        if(length>0)
        {
            length--;
        }
        return dynamic_array[length];
    }

    void resize() {
        capacity=2*capacity;
        int *new_dynamic_array=new int[capacity];
        for(int i=0;i<length;i++)
        {
            new_dynamic_array[i]=dynamic_array[i];
        }
        delete[] dynamic_array;
        dynamic_array=new_dynamic_array;
    }

    int getSize() {
        return length;
    }

    int getCapacity() {
        return capacity;
    }
};
