class Solution {
public:
    int minOperations(vector<string>& logs) {
        deque<string> step;
        int n=logs.size();
        for(int i=0;i<n;i++)
        {
            if(logs[i]=="../")
            {
                if(step.size()!=0)
                {
                    step.pop_back();
                }
            }else if(logs[i]=="./")
            {
                //nothing
            }else{
                step.push_back(logs[i]);
            }
        }
        return step.size();
    }
};