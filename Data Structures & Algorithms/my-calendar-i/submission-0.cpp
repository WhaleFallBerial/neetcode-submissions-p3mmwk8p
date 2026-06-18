class MyCalendar {
public:
    vector<pair<int, int>> dp;
    MyCalendar() {
        dp.clear();
    }
    
    bool book(int startTime, int endTime) {
        int n=dp.size();
        for(auto [s,e]:dp)
        {
            int maxs=max(startTime, s);
            int mine=min(endTime, e);
            if(maxs<mine)
            {
                return false;
            }
        }
        dp.push_back({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */