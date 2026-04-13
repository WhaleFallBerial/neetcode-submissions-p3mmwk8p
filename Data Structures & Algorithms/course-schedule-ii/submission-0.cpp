class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> pre_req;
        unordered_set<int> cycle;
        unordered_set<int> visit;
        vector<int> output;
        for(auto& p:prerequisites)
        {
            pre_req[p[0]].push_back(p[1]);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(!dfs(pre_req,cycle,visit,output,i)) return {};
        }
        return output;
    }
private:
    bool dfs(unordered_map<int,vector<int>>& pre_req,
    unordered_set<int>& cycle, unordered_set<int>& visit, vector<int>& output, int crs)
    {
        if(cycle.count(crs)) return false;
        if(visit.count(crs)) return true;

        cycle.insert(crs);
        if(pre_req.count(crs))
        {
            for(auto& p:pre_req[crs]) 
            {
                if(!dfs(pre_req,cycle,visit,output,p)) return false;
            }
        }
        cycle.erase(crs);
        visit.insert(crs);
        output.push_back(crs);
        return true;
    }
};
