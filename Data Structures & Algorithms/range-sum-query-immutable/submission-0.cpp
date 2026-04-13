class NumArray {
public:
    vector<int> dp;
    NumArray(vector<int>& nums) {
        dp=nums;
    }
    
    int sumRange(int left, int right) {
        int res=0;
        for(int i=left;i<=right;i++)
        {
            res+=dp[i];
        }
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */