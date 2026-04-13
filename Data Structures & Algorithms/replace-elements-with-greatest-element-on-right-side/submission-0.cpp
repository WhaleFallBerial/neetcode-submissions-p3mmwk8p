class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        
        int n=arr.size();
        vector<int> res(n,-1);
        for(int i=0;i<n-1;i++)
        {
            int maxv=INT_MIN;
            for(int j=i+1;j<n;j++)
            {
                maxv=max(maxv, arr[j]);
            }
            res[i]=maxv;
        }
        return res;
    }
};