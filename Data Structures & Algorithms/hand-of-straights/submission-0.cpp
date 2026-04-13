class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;

        unordered_map<int,int> count;
        for(auto& h:hand)
        {
            count[h]++;
        }
        sort(hand.begin(),hand.end());
        for(auto& h:hand)
        {
            if(count[h]>0)
            {
                for(int i=h;i<h+groupSize;i++)
                {
                    if(count[i]<=0) return false;
                    count[i]--;
                }
            }
        }
        return true;
    }
};
