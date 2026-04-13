class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        int n=arr.size();
        int closest=0;
        for(int i=0; i<arr.size();i++)
        {
            if(abs(arr[i]-x)<abs(arr[closest]-x)) closest=i;
        }
        int l=closest-1;
        int r=closest+1;
        res.push_back(arr[closest]);
        while(res.size()<k)
        {
            if(l>=0&&r<n)
            {
                if(abs(arr[l]-x)<=abs(arr[r]-x))
                {
                    res.push_back(arr[l--]);
                }else{
                    res.push_back(arr[r++]);
                }
            }else if(l>=0)
            {
                res.push_back(arr[l--]);
            }else if(r<n)
            {
                res.push_back(arr[r++]);
            }else{
                break;
            }
        }
        sort(res.begin(),res.end());
        return res;

    }
};