class Solution {
public:
    int findLucky(vector<int>& arr) {
        int maxv=*max_element(arr.begin(),arr.end());
        vector<int>dp(maxv+1,0);
        for(int i=0;i<arr.size();i++)
        {
            dp[arr[i]]++;
        }
        int res=INT_MIN;
        for(int i=0;i<dp.size();i++)
        {
            if(dp[i]==0) continue;
            if(dp[i]!=i) continue;
            res=max(res, i);
        }
        return (res==INT_MIN)?-1:res; 
    }
};