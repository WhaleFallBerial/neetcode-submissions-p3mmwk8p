class Solution {
public:
    int countPrimes(int n) {
        vector<int> prime;
        for(int i=2;i<n;i++)
        {
            bool prime_flag=true;
            for(int j=0;j<prime.size()&&prime[j]*prime[j]<=i;j++)
            {
                if(i%prime[j]==0)
                {
                    prime_flag=false;
                    break;
                }
            }
            if(prime_flag)
            {
                prime.push_back(i);
            }
        }
        int res=prime.size();
        return res;
    }
};