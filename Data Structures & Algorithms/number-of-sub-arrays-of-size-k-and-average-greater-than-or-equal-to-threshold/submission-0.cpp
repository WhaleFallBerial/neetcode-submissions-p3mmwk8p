class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int l=0,r=k-1;
        int n=arr.size();
        int res=0;
        while(l<n&&r<n)
        {
            float avg=0.0;
            for(int i=0;i<k;i++)
            {
                avg+=arr[l+i];
            }
            if((avg/(1.0*k)-threshold)>=0)
                res++;
            l++;
            r++;
        }
        return res;
    }
};