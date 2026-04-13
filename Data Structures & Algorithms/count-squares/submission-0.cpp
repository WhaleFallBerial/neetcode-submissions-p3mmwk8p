class CountSquares {
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        pcount[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int res=0;
        for(auto&[yi,cnt]:pcount[point[0]])
        {
            int side=abs(yi-point[1]);
            if(side==0) continue;
            res+=cnt*pcount[point[0]+side][point[1]]*pcount[point[0]+side][yi];
            res+=cnt*pcount[point[0]-side][point[1]]*pcount[point[0]-side][yi];
        }
        return res;
    }
private:
    unordered_map<int,unordered_map<int,int>> pcount;

};
