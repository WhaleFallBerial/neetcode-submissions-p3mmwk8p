class Solution {
    vector<int> dp;
public:
    Solution(vector<int>& w) {
        dp=w;
    }
    
    int pickIndex() {
        int sum=accumulate(dp.begin(),dp.end(),0);
        int r=rand()%sum;
        for(int i=0;i<dp.size();i++)
        {
            r-=dp[i];
            if(r<0)
                return i;
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */