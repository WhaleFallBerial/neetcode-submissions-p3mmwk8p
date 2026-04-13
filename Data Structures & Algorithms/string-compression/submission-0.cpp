class Solution {
public:
    int compress(vector<char>& chars) {
       int n=chars.size();
       int r=0, w=0;
       while(r<n)
       {
        char cur=chars[r];
        int cnt=0;
        while(r<n&&cur==chars[r])
        {
            r++;
            cnt++;
        }

        chars[w]=cur;
        w++;
        if(cnt>1)
        {
            string tmp=to_string(cnt);
            for(auto t:tmp)
            {
                chars[w]=t;
                w++;
            }
        }
       }
       return w;
    }
};