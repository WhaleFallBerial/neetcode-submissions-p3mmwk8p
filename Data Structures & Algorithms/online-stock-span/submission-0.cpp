class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int n=prices.size();
        int cnt=1;
        for(int i=n-1;i>=0;i--)
        {
            if(prices[i]<=price)
            {
                cnt++;
            }else{
                break;
            }
        }
        prices.push_back(price);
        return cnt;
    }
private:
    vector<int> prices;

};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */