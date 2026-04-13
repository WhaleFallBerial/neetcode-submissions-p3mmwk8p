class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())
        {
            return false;
        }
        
        unordered_map<char,int>compare_string;
        
        for(size_t i=0;i<s1.size();i++)
        {
            compare_string[s1[i]]++;
        }
        int need=compare_string.size();
        for(size_t i=0;i<s2.size();i++)
        {
            
            unordered_map<char,int>count;
            int curr=0;
            for(size_t j=i;j<s2.size();j++)
            {
                count[s2[j]]++;
                if(compare_string[s2[j]]<count[s2[j]])
                {
                    break;
                }
                if(compare_string[s2[j]]==count[s2[j]])
                {
                    curr++;
                }
                if(need==curr)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
