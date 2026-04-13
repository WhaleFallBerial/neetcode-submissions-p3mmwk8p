// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        int n = pairs.size();
        vector<vector<Pair>> retrunvalue;
        for(int cnt=0;cnt<n;cnt++)
        {
            int swap_cnt=cnt-1;
            while(swap_cnt>=0 && pairs[swap_cnt].key>pairs[swap_cnt+1].key)
            {
                swap(pairs[swap_cnt],pairs[swap_cnt+1]);
                swap_cnt--;
            }
            retrunvalue.push_back(pairs);
        }
        return retrunvalue;
    }
};
