class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
        int res=INT_MAX;
        
        int l=0, r=k-1;
        while(l<n&&r<n)
        {
            int bcnt=0;
            for(int i=l;i<=r;i++)
            {
                if(blocks[i]=='W') bcnt++;
            }
            res=min(res,bcnt);
            l++;
            r++;
        }
        return res;
    }
};