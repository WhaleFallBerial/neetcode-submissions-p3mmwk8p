class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int flag=true;
        for(int i=digits.size()-1;i>=0;i--)
        {
            if(flag) 
            {
                digits[i]+=1;
                flag=false;
            }
            if(digits[i]>=10){
                digits[i]%=10;
                flag=true;
            }
        }
        if(flag)
        {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
