class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        mem.assign(nums.size()+2,vector<int>(nums.size()+2,-1));
        vector<int> nn(nums.size()+2,1);
        for(int i=0;i<nums.size();i++)
        {
            nn[i+1]=nums[i];
        }
        return dfs(nn, 1, nn.size()-2);
    }
private:
    vector<vector<int>> mem;
    int dfs(vector<int>& nums, int l, int r)
    {
        if(l>r) return 0;
        if(mem[l][r]!=-1) return mem[l][r];
        for(int i=l;i<=r;i++)
        {
            int c=nums[l-1]*nums[i]*nums[r+1];
            c+=dfs(nums,i+1,r)+dfs(nums,l, i-1);
            mem[l][r]=max(mem[l][r],c);
        }
        return mem[l][r];
    }
};
