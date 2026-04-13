class Solution {
public:
    int maxDifference(string s) {
        vector<int> oddvec;
        vector<int> evenvec;
        for(int i=0;i<26;i++)
        {
            int tmp=0;
            for(int j=0;j<s.size();j++)
            {
                if((s[j]-'a')==i) tmp++;
            }
            if(tmp==0)
            {
                continue;
            }else if(tmp%2==0)
            {
                evenvec.push_back(tmp);
            }else{
                oddvec.push_back(tmp);
            }
        }
        int maxodd=*max_element(oddvec.begin(), oddvec.end());
        int minodd=*min_element(oddvec.begin(), oddvec.end());
        int maxeven=*max_element(evenvec.begin(), evenvec.end());
        int mineven=*min_element(evenvec.begin(), evenvec.end());
        return maxodd-mineven;
        
    }
};