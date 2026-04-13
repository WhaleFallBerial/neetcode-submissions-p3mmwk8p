class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        dfs(0,0,{},candidates,target);
        return res;
    }
    void dfs(int i,int total, vector<int> cur, vector<int>& candidates, int target)
    {
        if(total==target)
        {
            res.push_back(cur);
            return;
        }

        for(int j=i;j<candidates.size();j++)
        {
            if(total+candidates[j]>target) return;
            if((j>i) && (candidates[j]==candidates[j-1])) continue;
            cur.push_back(candidates[j]);
            dfs(j+1,total+candidates[j],cur,candidates,target);
            cur.pop_back();
        }
    }
};
