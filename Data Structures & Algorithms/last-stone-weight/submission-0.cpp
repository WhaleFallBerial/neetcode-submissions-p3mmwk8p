class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        vector<int> res=stones;
        sort(res.rbegin(),res.rend());
        while(res[1]!=0)
        {
            res[0]=res[0]-res[1];
            res[1]=0;
            sort(res.rbegin(),res.rend());

        }
        return res[0];
    }
};
