class KthLargest {
public:
    int kindex;
    vector<int> elems;
    KthLargest(int k, vector<int>& nums) {
        elems=nums;
        kindex=k;
    }
    
    int add(int val) {
        elems.push_back(val);
        sort(elems.rbegin(),elems.rend());
        return elems[kindex-1];
    }
};
