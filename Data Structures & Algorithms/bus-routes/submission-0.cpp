class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
        unordered_map<int, vector<int>> mp;
        for(int i=0;i<routes.size();i++)
        {
            for(int j=0;j<routes[i].size();j++)
            {
                mp[routes[i][j]].push_back(i);
            }
        }

        int n=routes.size();
        int res=0;

        deque<int> dq;
        dq.push_back(source);
        vector<bool> v(n, false);

        while(!dq.empty())
        {
            
            int sz=dq.size();
            for(int i=0;i<sz;i++)
            {
                int stop=dq.front();
                dq.pop_front();
                if(stop==target)
                {
                    return res;
                }
                for(int j=0;j<mp[stop].size();j++)
                {
                    if(!v[mp[stop][j]])
                    {v[mp[stop][j]]=true;
                    for(int k=0;k<routes[mp[stop][j]].size();k++)
                    {
                        dq.push_back(routes[mp[stop][j]][k]);
                    }
                    }
                    
                }

            }
            res++;
        }
        return -1;
    }
};