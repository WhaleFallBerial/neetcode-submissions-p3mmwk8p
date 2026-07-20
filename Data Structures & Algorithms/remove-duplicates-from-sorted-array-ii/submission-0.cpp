class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int i=2;
        while(i<nums.size())
        {
            int cnt=1;
            for(int j=0;j<i;j++)
            {
            
                if(cnt<=0 && nums[i]==nums[j])
                {
                    nums.erase(nums.begin()+i);
                    i--;
                    break;
                }else if(nums[i]==nums[j]){
                    cnt--;
                }
            }
            i++;
        }
        int res=nums.size();
        return res;
    }
};