class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0;i<numCourses;i++)
        {
            pre_crs[i]={};
        }
        for(auto& pre:prerequisites)
        {
            pre_crs[pre[0]].push_back(pre[1]);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(!dfs(i)) return false;
        }
        return true;
    }
private:
    unordered_set<int> visit;
    unordered_map<int,vector<int>> pre_crs;
    bool dfs(int crs)
    {
        if(visit.count(crs)) return false;
        if(pre_crs[crs].empty()) return true;
        visit.insert(crs);
        for(auto& c:pre_crs[crs])
        {
            if(!dfs(c)) return false;
        }
        visit.erase(crs);
        pre_crs[crs].clear();
        return true;
    }
};
