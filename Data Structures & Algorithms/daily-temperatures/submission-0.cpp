class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> res(n,0);
        for(auto i=0; i<n; i++)
        {
            int count=1;
            int j=i+1;
            while(j<n)
            {
                if(temperatures[j]>temperatures[i])
                {
                    break;
                }
                j++;
                count++;
            }
            if(j==n)
            {
                res[i]=0;
            }else{
                res[i]=count;
            }
        }
        return res;
    }
};
