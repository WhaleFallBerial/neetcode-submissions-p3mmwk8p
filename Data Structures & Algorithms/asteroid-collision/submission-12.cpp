class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for(auto& a:asteroids)
        {
            while(!res.empty()&&a<0&&res.back()>0)
            {
                int diff=a+res.back();
                if(diff>0)
                {
                    a=0;
                }else if(diff<0)
                {
                    res.pop_back();
                }else{
                    a=0;
                    res.pop_back();
                }
            }
            if(a!=0) res.push_back(a);
        }
        return res;
    }
};