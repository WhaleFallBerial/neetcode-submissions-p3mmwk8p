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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* cur=head;
        vector<int> arr;

        while(cur)
        {
           if(cur->val!=val)
           {
            arr.push_back(cur->val);
           }
           cur=cur->next;
        }
        if(arr.empty()) return nullptr;
        ListNode* res=new ListNode(arr[0]);
        cur=res;
        for(int i=1;i<arr.size();i++)
        {
            cur->next=new ListNode(arr[i]);
            cur=cur->next;
        }
        return res;
    }
};