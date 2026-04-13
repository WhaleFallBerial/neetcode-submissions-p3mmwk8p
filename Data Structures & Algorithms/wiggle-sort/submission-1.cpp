class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> adj=nums;
        int n=nums.size();
        int odd_flag=nums.size()%2;
        nums.clear();
        for(int i=0;i<n/2;i++)
        {
            nums.push_back(adj[i]);
            nums.push_back(adj[n-1-i]);
        }   
        if(odd_flag)
        {
            nums.push_back(adj[n/2+1]);
        }
    }
};
