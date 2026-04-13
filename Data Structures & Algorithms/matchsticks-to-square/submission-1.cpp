class Solution {
    bool dfs(vector<int>& matchsticks, vector<int>&side,int i, int length)
    {
        if(i==matchsticks.size()) 
            return side[0]==length && side[1]==length && side[2]==length && side[3]==length;
        
        for(int j=0;j<4;j++)
        {
            if(side[j]+matchsticks[i]<=length)
            {
                side[j]+=matchsticks[i];
                if(dfs(matchsticks,side,i+1,length)) return true;
                side[j]-=matchsticks[i];
            }
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int total=0;
        for(auto& m:matchsticks)
        {
            total+=m;
        }
        int length=total/4;
        if(total%4!=0) return false;
        sort(matchsticks.rbegin(),matchsticks.rend());
        vector<int> side(4,0);
        return dfs(matchsticks,side,0,length);

    }
};