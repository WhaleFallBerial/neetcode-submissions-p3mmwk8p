class Solution {
    int dfs(int i, int last, vector<int>& flowerbed, vector<vector<int>>& memo)
    {
        if(i>=flowerbed.size()) return 0;
        if(memo[i][last]!=-1) return memo[i][last];
        if(flowerbed[i]==1)
        {
            memo[i][last]=dfs(i+1,1, flowerbed, memo);
            return memo[i][last];
        }
        int noplant=dfs(i+1, 0, flowerbed, memo);
        int plant=0;
        bool canplant=false;
        if((flowerbed[i]==0)&&last==0) canplant=true;
        if(i<flowerbed.size()-1) canplant=canplant&&(flowerbed[i+1]==0);
        if(canplant) plant=(dfs(i+1, 1, flowerbed, memo)+1);
        memo[i][last]=max(plant, noplant);
        return memo[i][last];
    }
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m=flowerbed.size();
        vector<vector<int>> memo(m, vector<int>(2,-1));
        int maxflowers=dfs(0, 0 ,flowerbed, memo);
        return maxflowers>=n;
        
    }
};