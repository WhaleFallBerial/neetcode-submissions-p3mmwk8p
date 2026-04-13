class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> res;
        for(auto& o:operations)
        {
            if(o=="+")
            {
                res.push_back(res[res.size()-1]+res[res.size()-2]);
            }else if(o=="D")
            {
                res.push_back(res[res.size()-1]*2);
            }else if(o=="C")
            {
                res.erase(res.begin()+res.size()-1);
            }else{
                res.push_back(stoi(o));
            }

        }
        int sum=0;
        for(auto& r:res)
        {
            sum+=r;
        }
        return sum;
    }
};