class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int left=0, right=n-1;
        int cnt=0;
        int res=0;
        for(int i=0;i<k;i++)
        {
            res+=cardPoints[i];
        }
        left=k-1;
        int tmp=res;
        while(left>=0)
        {
            tmp=tmp-cardPoints[left]+cardPoints[right];
            res=max(res, tmp);
            left--;
            right--;
        }
        return res;
    }
};