class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int l=0,r=-1;
        int res=1;
        for(int i=0;i<n;i++)
        {
            int tmp=1;
            l=fruits[i];
            r=-1;
            int j=i+1;
            while(j<n)
            {
                if(fruits[j]!=l&&fruits[j]!=r&&r!=-1)
                {
                    break;
                }else if(fruits[j]!=l&&r==-1)
                {
                    r=fruits[j];
                }
                tmp++;
                j++;
            }
            res=max(res, tmp);

        }
        return res;
    }
};