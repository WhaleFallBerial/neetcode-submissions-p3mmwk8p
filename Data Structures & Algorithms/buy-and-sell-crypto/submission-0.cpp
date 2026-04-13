class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        int minprice=prices[0];
        for(auto sell:prices)
        {
            res=max(res,sell-minprice);
            minprice=min(minprice,sell);
        }
        return res;
    }
};
