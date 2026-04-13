class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        unordered_map<string, vector<string>> adj;
        set<string> webset;
        vector<pair<int,int>> resort;
        int n=username.size();
        for(int i=0;i<n;i++) resort.push_back({timestamp[i],i});
        sort(resort.begin(),resort.end());
        for(int i=0;i<n;i++)
        {
            adj[username[resort[i].second]].push_back(website[resort[i].second]);
            webset.insert(website[i]);
        }
        int u=adj.size();
        int w=webset.size();
        vector<string> ws=vector<string>(webset.begin(),webset.end());
        int rescnt=0;
        vector<string> res;
        for(int i=0;i<w;i++)
        {
            for(int j=0;j<w;j++)
            {
                for(int k=0;k<w;k++)
                {
                    int tmp=0;
                    for(auto [a,b]:adj)
                    {

                        auto iter=find(b.begin(),b.end(),ws[i]);
                        if(iter!=b.end())
                        {
                            iter=find(1+iter,b.end(),ws[j]);
                            if(iter!=b.end())
                            {
                                iter=find(1+iter,b.end(),ws[k]);
                                if(iter!=b.end()) tmp++;
                            }
                        }
                    }
                    if(tmp>rescnt)
                    {
                        rescnt=tmp;
                        res.clear();
                        res.push_back(ws[i]);
                        res.push_back(ws[j]);
                        res.push_back(ws[k]);
                    }
                }
            }
        }
        return res;
    }
};