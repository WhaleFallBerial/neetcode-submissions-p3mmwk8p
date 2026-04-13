class Solution {
public:
    string largestGoodInteger(string num) {
        vector<int>res;
        int cnt=0;
        for(auto i=1;i<num.size();i++)
        {
           
            if(num[i-1]==num[i]) 
            {
                cnt++;
            }else{
                cnt=0;
            }
            if(cnt==2) res.push_back((num[i]-'0'));
        }
        stringstream ss;
        if(res.size()==0) 
        {
            return "";
        }
        else
        {
            int maxv=(*max_element(res.begin(),res.end()));
            ss<<maxv<<maxv<<maxv;
            string ans=ss.str();
            return ans;
        }
    }
};