class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        unordered_map<int,int> tmp;
        for (int i = 0; i < n+1; i++) {
    tmp[i] = 0;
}
        for(auto& t: trust)
        {
            tmp[t[0]]=-1;
            if(tmp[t[1]]!=-1) tmp[t[1]]++;

        }
        int s=tmp.size();
        int flag=0;
        int res;
        for(int i=1;i<=n;i++)
        {        
            if(tmp[i]==n-1) 
            {
                res=i;
                flag++;
            }
                
        }
        if(flag==1) return res;
        else return -1;
    }
};