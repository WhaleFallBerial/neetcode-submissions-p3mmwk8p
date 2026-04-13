class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=l+1;
        int res=0;
        
        for(int l=0;l<n;l++)
        {
            int r=l;
            int flipcnt=0;
            int tmp=0;
            while(l<n&&r<n&&flipcnt<=k)
            {
                if(nums[r]!=1)
                {
                    flipcnt++;
                    if(flipcnt<=k)
                    {
                        tmp++;
                    }else{
                        break;
                    }
                }else{
                    tmp++;
                }
                res=max(res,tmp);
                r++;
            }
        }
        return res;

    }
};