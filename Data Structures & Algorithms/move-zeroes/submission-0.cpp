class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int z=0, x=0;
        int n=nums.size();
        while(x<n)
        {
            if(nums[x]==0)
            {
                for(int i=x+1;i<n;i++)
                {
                    if(nums[i]!=0) 
                    {
                        int tmp=nums[i];
                        nums[i]=0;
                        nums[x]=tmp;
                        break;
                    }
                }
            }
            x++;
        }
    }
};