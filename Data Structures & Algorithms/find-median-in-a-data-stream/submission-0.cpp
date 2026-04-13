class MedianFinder {
public:
    vector<int> res;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        res.push_back(num);
    }
    
    double findMedian() {
        sort(res.begin(),res.end());
        if(res.size()%2)
        {
            return static_cast<double>(res[res.size()/2]);
        }else{
            return (res[(res.size()/2) -1]+res[res.size()/2])/2.0;
        }
    }
};
