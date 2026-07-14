class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> mp;
        int res=0;
        for( auto c:chars)
        {
            mp[c]++;
        }
        for(auto w:words)
        {
            unordered_map<char, int> tmp;
            bool cnt_flag=true;
            for(auto c:w)
            {
                tmp[c]++;
                if(!mp.count(c))
                {
                    cnt_flag=false;
                    break;
                }else if(mp[c]<tmp[c])
                {
                    cnt_flag=false;
                    break;
                }


            }
            if(cnt_flag)
            {
                res+=w.size();
            }
        }
        return res;
    }
};