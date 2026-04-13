class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        deque<int> dp;
        for(auto n:nums)
        {
            if(n%2==1)
            {
                dp.push_back(n);
            }else{
                dp.push_front(n);
            }
        }
        return vector<int>(dp.begin(),dp.end());
    }
};