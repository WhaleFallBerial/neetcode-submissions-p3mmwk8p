class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n=details.size();
        int res=0;
        for(int i=0;i<n;i++)
        {
            if((details[i][11]-'6'>0)||((details[i][11]-'6'==0)&&(details[i][12]-'0'>0))) res++;
        }
        return res;
    }
};