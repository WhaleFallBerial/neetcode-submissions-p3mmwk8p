class Solution {
public:
    int findKthNumber(int n, int k) {
        
        long long cur=1;
        k--;
        while(k>0)
        {
            long long cnt=count(cur, n);
            if(cnt<=k)
            {
                k-=cnt;
                cur++;
            }else{
                k--;
                cur*=10;
            }
        } 
        return (int)cur;
    }

    long long count(long long cur, int n)
    {
        long long left=cur;
        long long right=cur;
        long long total=0;
        while(left<=n)
        {
            total+=min(right, (long long)n)-left+1;
            left*=10;
            right=right*10+9;
        }
        return total;
    }
};