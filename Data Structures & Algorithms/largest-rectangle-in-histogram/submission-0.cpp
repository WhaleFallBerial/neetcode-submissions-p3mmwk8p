class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int res=0;
        for(auto i=0;i<n;i++)
        {
            int height=heights[i];
            int right=i;
            while(right<n&&heights[right]>=height)
            {
                right++;
            }
            int left=i-1;
            while(left>=0&&heights[left]>=height)
            {
                left--;
            }
            left++;
            right--;
            res=max(res, (right-left+1)*height);
        }
        return res;
    }
};
