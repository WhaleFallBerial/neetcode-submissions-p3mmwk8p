class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        int n=nums.size();
        vector<string> adj;
        for(auto a:nums) adj.push_back(to_string(a));

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                string tmp_i=adj[i];
                string tmp_j=adj[j];
                if(tmp_i+tmp_j<tmp_j+tmp_i)
                {
                    adj[i]=tmp_j;
                    adj[j]=tmp_i;
                }
            }
        }

        for(auto b:adj)
        {
            res+=b;
        }
        if(res[0]=='0') return "0";
        return res;
    }
};