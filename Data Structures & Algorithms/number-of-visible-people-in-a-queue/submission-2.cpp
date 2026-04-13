class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int l=0;
        int n=heights.size();
        vector<int> res(n,0);
        if(n==1)
        {
            return res;
        }
        
        while(l<n-2)
        {
            int tmp=1;
            for(int r=n-1;r>l+1;r--)
            {
                int st=min(heights[l],heights[r]);
                int bt=*max_element(heights.begin()+l+1,heights.begin()+r);
                if(st>bt)
                {
                    tmp++;
                }
            }
            res[l]=tmp;
            l++;
        }
        res[n-2]=1;
        res[n-1]=0;
        return res;
    }
};