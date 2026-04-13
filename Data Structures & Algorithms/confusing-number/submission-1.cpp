class Solution {
public:
    bool confusingNumber(int n) {
        vector<int> dp;
        int m=n;
        while(m>0)
        {
            int v=m%10;
            m/=10;
            switch(v)
            {
                case 0:
                    dp.push_back(0);
                    break;
                case 1:
                    dp.push_back(1);
                    break;
                case 2:
                    return false;
                    break;
                case 3:
                    return false;
                    break;
                case 4:
                    return false;
                    break;
                case 5:
                    return false;
                    break;
                case 6:
                    dp.push_back(9);
                    break;
                case 7:
                    return false;
                    break;
                case 8:
                    dp.push_back(8);
                    break;
                case 9:
                    dp.push_back(6);
                    break;
            }
        }

        stringstream ss;
        for(auto d:dp)
        {
            ss<<d;
        }
        int res=0;
        ss>>res;
        return res==n?false:true;
    }
};
