class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res={{}};
    for(auto num:nums)
    {
        vector<vector<int>> tmp;
        for(auto v:res)
        {
            for(auto i=0;i<=v.size();i++)
            {
                vector<int> vt=v;
                vt.insert(vt.begin()+i,num);
                tmp.push_back(vt);
            }
        }
        res=tmp;
    }
    return res;
    }
};
