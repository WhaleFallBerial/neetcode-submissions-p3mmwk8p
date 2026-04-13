class Solution {
    set<vector<int>> res;
    void dfs(vector<int>& nums, vector<int>& perm)
    {
        if(nums.size()==perm.size())
        {
            res.insert(perm);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=INT_MIN)
            {
                int tmp=nums[i];
                perm.push_back(tmp);
                nums[i]=INT_MIN;
                dfs(nums,perm);
                perm.pop_back();
                nums[i]=tmp;
            }
        }

    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> perm;

        dfs(nums,perm);
        return vector<vector<int>>(res.begin(),res.end());
    }
};