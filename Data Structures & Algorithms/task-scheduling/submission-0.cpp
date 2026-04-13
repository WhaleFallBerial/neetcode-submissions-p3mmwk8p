class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);
        for( auto i:tasks)
        {
            count[i-'A']++;
        }
        sort(count.begin(),count.end());
        int maxc=count[25];
        int idle=(maxc-1)*n;

        for(auto i=24;i>=0;i--)
        {
            idle-=min(maxc-1,count[i]);
        }
        return max(0,idle)+tasks.size();
    }
};
