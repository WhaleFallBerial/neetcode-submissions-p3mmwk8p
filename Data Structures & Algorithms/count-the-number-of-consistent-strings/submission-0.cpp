class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> a_set;
        for(auto a:allowed)
        {
            a_set.insert(a);
        }
        int res=0;
        for(auto w:words)
        {
            bool cnt_flag=true;
            for(auto c:w)
            {
                if(!a_set.count(c))
                {
                    cnt_flag=false;
                    break;
                }
            }
            if(cnt_flag)
            {
                res++;
            }
        }
    return res;
    }
};