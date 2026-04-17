/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> arr;
        ListNode* cur=head;
        while(cur)
        {
            arr.push_back(cur->val);
            cur=cur->next;
        }
        int n=arr.size();
        int res=INT_MIN;
        for(int i=0;i<n/2;i++)
        {
            res=max(res,arr[i]+arr[n-i-1]);
        }
        return res;
    }
};