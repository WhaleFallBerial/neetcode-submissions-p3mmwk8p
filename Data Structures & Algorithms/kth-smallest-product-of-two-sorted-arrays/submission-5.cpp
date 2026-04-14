class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        vector<int> n1p, n1n, n2p, n2n;
        int index=0;
        for(auto n1:nums1)
        {
            if(n1<0)
            {
                n1n.push_back(n1);
            }else{
                n1p.push_back(n1);
            }
        }
        for(auto n2:nums2)
        {
            if(n2<0)
            {
                n2n.push_back(n2);
            }else{
                n2p.push_back(n2);
            }
        }
        vector<long long> res;
        int m1=n1n.size(), m2=n2n.size();
        int p1=n1p.size(), p2=n2p.size();
        if((m1==0 && m2==0)||(p1==0&&p2==0))
        {
        for(int i1=0;i1<nums1.size();i1++)
        {
            for(int i2=0;i2<nums2.size();i2++)
            {
                res.push_back(nums1[i1]*nums2[i2]);
            }
        }
        index=k-1;
        }else{
            if(m1*n2p.size()+m2*n1p.size()>=k)
            {
                for(int i1=0;i1<m1;i1++)
                {
                    for(int i2=0;i2<n2p.size();i2++)
                    {
                        res.push_back(n1n[i1]*n2p[i2]);
                    }
                }
                for(int i1=0;i1<n1p.size();i1++)
                {
                    for(int i2=0;i2<m2;i2++)
                    {
                        res.push_back(n1p[i1]*n2n[i2]);
                    }
                }
                index=k-1;
            }else{
                long long tmp=k-(m1*n2p.size()+m2*n1p.size());
                for(int i1=0;i1<n1p.size();i1++)
                {
                    for(int i2=0;i2<n2p.size();i2++)
                    {
                        res.push_back(n1p[i1]*n2p[i2]);
                    }
                }
                for(int i1=0;i1<n1n.size();i1++)
                {
                    for(int i2=0;i2<n2n.size();i2++)
                    {
                        res.push_back(n1n[i1]*n2n[i2]);
                    }
                }
                index=tmp-1;
            }
        }
        sort(res.begin(),res.end());

        return res[index];
    }
};