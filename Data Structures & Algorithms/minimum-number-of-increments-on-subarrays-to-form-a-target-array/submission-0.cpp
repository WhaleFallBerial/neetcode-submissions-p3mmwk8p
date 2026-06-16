class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n=target.size();
        int res=target[0];
        for(int i=1;i<n;i++)
        {
            res+=max(0, target[i]-target[i-1]);
        }
        return res;
    }
};