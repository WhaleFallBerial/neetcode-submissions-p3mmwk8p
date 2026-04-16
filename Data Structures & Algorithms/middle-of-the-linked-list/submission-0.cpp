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
    ListNode* middleNode(ListNode* head) {
        ListNode* cur=head;
        vector<int> arr;
        while(cur)
        {
            arr.push_back(cur->val);
            cur=cur->next;
        }
        int n=arr.size();
        int mid=n/2;
        ListNode* res=new ListNode(arr[mid]);
        cur=res;
        for(int i=mid+1;i<n;i++)
        {
            cur->next=new ListNode(arr[i]);
            cur=cur->next;
        }
        return res;

    }
};