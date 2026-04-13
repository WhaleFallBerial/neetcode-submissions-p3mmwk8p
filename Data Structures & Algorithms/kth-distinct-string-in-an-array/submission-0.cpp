class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> dp;

        for(auto a:arr)
        {
            if(dp.find(a)!=dp.end())
            {
                dp[a]++;
            }else{
                dp.insert({a,1});
            }

        }
        for(int i=0;i<arr.size();i++)
        {
            if(dp[arr[i]]!=1)
            {
                continue;
            }else{
                k--;
                if(k==0) return arr[i];
            }
        }
        if(k>0) return "";
    }
};