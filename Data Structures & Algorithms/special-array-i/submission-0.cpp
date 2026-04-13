class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int res=true;
        int even_flag=-1;
        for(auto n:nums)
        {
            if(even_flag==1)
            {
                if(n%2!=1) return false;
                even_flag=0;
            }else if(even_flag==0)
            {
                if(n%2!=0) return false;
                even_flag=1;
            }else{
                if(n%2==1) 
                    even_flag=0;
                else
                    even_flag=1;
            }
        }
        return true;
    }
};