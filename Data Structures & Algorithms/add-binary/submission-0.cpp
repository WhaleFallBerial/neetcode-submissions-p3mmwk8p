class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int carry=0;
        int a_cnt=a.size();
        int b_cnt=b.size();
        while((a_cnt>0)||(b_cnt>0)||(carry!=0))
        {
            int digital_a=a_cnt>0?a[a_cnt-1]-'0':0;
            int digital_b=b_cnt>0?b[b_cnt-1]-'0':0;
            
            res+=(digital_a+digital_b+carry)%2+'0';
            carry=(digital_a+digital_b+carry)/2;
            a_cnt--;
            b_cnt--;

        }
        reverse(res.begin(),res.end());
        return res;
    }
};