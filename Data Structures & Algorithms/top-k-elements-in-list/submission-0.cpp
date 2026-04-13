class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> res;
        for(auto i=0; i<nums.size();i++)
        {
            res[nums[i]]++;
        }
        vector<vector<int>> result(nums.size()+1);
        for(auto i:res)
        {
            result[i.second].push_back(i.first);

        }
        vector<int>outputv;
        for(int i=result.size()-1;i>0;i--)
        {
            for(int n:result[i])
            {
                outputv.push_back(n);
                if(outputv.size()==k){
                    return outputv;
                }
            }
        }
        return outputv;
        
    }
};
