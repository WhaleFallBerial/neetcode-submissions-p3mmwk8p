class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int res=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int ni=words[i].size();
                int nj=words[j].size();
                if(ni>nj) continue;
                int idx=0;
                while(idx<ni)
                {
                    if(words[i][idx]==words[j][idx]&&words[i][idx]==words[j][nj-ni+idx])
                    {
                        idx++;
                    }else{
                        break;
                    }
                    
                }
                if(idx==ni) res++;
            }
        }
        return res;
    }
};