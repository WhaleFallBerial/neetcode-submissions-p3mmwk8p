class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<int> indices;
        for(int i=0;i<n;i++)
        {
            indices.emplace_back(i);
        }
        sort(indices.begin(), indices.end(), [&](int a, int b){
            return capital[a]<capital[b];
        });
        priority_queue<int>maxp;
        int idx=0;
        for(int i=0;i<k;i++)
        {
            while(idx<n&&capital[indices[idx]]<=w)
            {
                maxp.push(profits[indices[idx]]);
                idx++;
            }
            if(maxp.empty()) break;
            w+=maxp.top();
            maxp.pop();
        }
        return w;
    }
};