class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        for(int i=0;i<n;i++)
        {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(),tasks.end());
        vector<int> res;
        priority_queue<pair<int, int>,vector<pair<int, int>>, greater<>> min_heap;
        int i=0;
        long long time=tasks[0][0];
        while(!min_heap.empty()||i<n)
        {
            while(i<n&&time>=tasks[i][0])
            {
                min_heap.push({tasks[i][1],tasks[i][2]});
                i++;
            }
            if(min_heap.empty())
            {
                time=tasks[i][0];
            }else{
                auto [proct,index]=min_heap.top();
                min_heap.pop();
                time+=proct;
                res.push_back(index);
            }
        }
        return res;
    }
};