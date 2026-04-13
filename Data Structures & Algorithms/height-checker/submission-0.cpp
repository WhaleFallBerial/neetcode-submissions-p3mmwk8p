class Solution {
public:
    int heightChecker(vector<int>& heights) {
     vector<int> adj=heights;
     sort(adj.begin(),adj.end());
     int n=heights.size();
     int res=0;
     for(int i=0;i<n;i++)
     {
        if(heights[i]!=adj[i]) res++;
     }   
     return res;
    }
};