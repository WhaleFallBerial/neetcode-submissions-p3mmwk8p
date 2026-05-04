class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long res=0;
        for(int i=0;i<k;i++)
        {
            int idx=max_element(gifts.begin(),gifts.end())-gifts.begin();
            gifts[idx]=sqrt(gifts[idx]);
        }
        res=accumulate(gifts.begin(),gifts.end(),0);
        return res;
    }
};