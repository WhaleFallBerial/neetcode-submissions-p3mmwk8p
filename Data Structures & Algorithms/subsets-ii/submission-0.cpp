class Solution {
public:
    set<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        dfs(0,nums,{});
        return vector<vector<int>>(res.begin(),res.end());

    }

    void dfs(int idx, vector<int>& nums, vector<int> cur)
    {
        if(idx==nums.size())
        {
            res.insert(cur);
            return;
        }

        cur.push_back(nums[idx]);
        dfs(idx+1,nums,cur);
        cur.pop_back();
        dfs(idx+1,nums,cur);
    }
};
