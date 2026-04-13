class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        vector<int> adj(n,0);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(grumpy[i]==1)
            {
                adj[i]=customers[i];
            }else{
                cnt+=customers[i];
            }
        }
        int l=0, r=minutes-1;
        int res=0;
        while(l<n&&r<n)
        {
            int tmp=0;
            for(int i=l;i<=r;i++)
            {
                tmp+=adj[i];
            }
            res=max(res, tmp);
            l++;
            r++;
        }
        return res+cnt;
    }
};