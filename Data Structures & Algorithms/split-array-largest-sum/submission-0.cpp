class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int maxv=*max_element(nums.begin(),nums.end());
        while(true)
        {
            int cap=maxv;
            int sa=1;
            for(auto& n:nums)
            {
                if(cap-n<0)
                {
                    sa++;
                    cap=maxv;
                }
                cap-=n;
            }

            if(sa>k)
            {
                maxv++;
            }else{
                 return maxv;
            }
        }
        return maxv;
    }
};