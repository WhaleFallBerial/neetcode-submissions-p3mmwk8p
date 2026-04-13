class Solution {
public:
    string removeDuplicates(string s, int k) {
        string tmp=s;
        int index=1;
        char comp=tmp[0];
        int cnt=1;
        int n=s.size();
        while(index<n)
        {
            if(tmp[index]==comp)
            {
                cnt++;
                if(cnt>=k)
                {
                    for(int i=index-k+1;i+k<n;i++)
                    {
                        tmp[i]=tmp[i+k];
                    }
                    n-=k;
                    index=0;
                    comp=tmp[0];
                    cnt=1;
                }
            }else{
                comp=tmp[index];
                cnt=1;
            }
            index++;
        }
        string res(tmp.begin(),tmp.begin()+n);
        return res;
    }
};