class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> freq;
        for(auto &c:s)
        {
            freq[c]++;
        }
        auto maxp=*max_element(freq.begin(),freq.end(),[](const auto& a,const auto& b){
            return a.second < b.second;
        });
        if(maxp.second>(s.size()+1)/2) return "";
        string res;
        while(res.size()<s.size())
        {
            auto maxp1=*max_element(freq.begin(),freq.end(),[](const auto& a,const auto& b){
            return a.second < b.second;
        });
        res+=maxp1.first;
        freq[maxp1.first]--;
        if(freq[maxp1.first]==0) continue;
        auto tmp=freq[maxp1.first];
        freq[maxp1.first]=INT_MIN;
        auto maxp2=*max_element(freq.begin(),freq.end(),[](const auto& a,const auto& b){
            return a.second < b.second;
        });
        res+=maxp2.first;
        freq[maxp2.first]--;
        freq[maxp1.first]=tmp;
        }
        return res;
    }
};