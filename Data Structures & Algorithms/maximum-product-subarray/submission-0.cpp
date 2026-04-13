class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxres=INT_MIN;
     for(int i=0;i<nums.size();i++)
     {
        int prod=nums[i];
        maxres=max(maxres, prod);
        for(int j=i+1;j<nums.size();j++)
        {
            prod*=nums[j];
            maxres=max(maxres, prod);
        }
     }
     return maxres;
    }

};
