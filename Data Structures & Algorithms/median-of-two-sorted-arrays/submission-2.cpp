class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A=nums1;
        vector<int>& B=nums2;
        int total=A.size()+B.size();
        int half=(total+1)/2;
        if(A.size()>B.size())
        {
            swap(A,B);
        }
        int l=0;
        int r=A.size();
        while(l<=r)
        {
            int i=l+(r-l)/2;
            int j=half-i;
            int al=i>0?A[i-1]:INT_MIN;
            int ar=i<A.size()?A[i]:INT_MAX;
            int bl=j>0?B[j-1]:INT_MIN;
            int br=j<B.size()?B[j]:INT_MAX;
            if(al<=br&&ar>=bl)
            {
                if(total%2==0)
                {
                    return static_cast<double>(max(al,bl)+min(ar,br))/2.0;
                }else{
                    return static_cast<double>(max(al,bl));
                }
            } else if (ar<bl){
                l=i+1;
            } else{
                r=i-1;
            }
        }
        return -1;
    }
};
