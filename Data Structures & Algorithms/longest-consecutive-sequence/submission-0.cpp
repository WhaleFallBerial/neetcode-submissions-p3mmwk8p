class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nset(nums.begin(),nums.end());
        int longest=0;
        for(auto num:nset)
        {
            if(nset.find(num-1)==nset.end())
            {
                int length=1;
                while(nset.find(num+length)!=nset.end())
                {
                    length++;
                }
                longest=max(length,longest);
            }
        }
        return longest;
    }
};
