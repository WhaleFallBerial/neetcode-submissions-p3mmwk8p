class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
     sort(nums.begin(),nums.end());
     int res=INT_MAX;
     int l=0,r=k-1,n=nums.size();
     while(l+k-1<n)
     {
        int ma=*max_element(nums.begin()+l,nums.begin()+l+k);
        int mi=*min_element(nums.begin()+l,nums.begin()+l+k);
        res=min(res,ma-mi);
        l++;
     }   
     return res;
    }
};