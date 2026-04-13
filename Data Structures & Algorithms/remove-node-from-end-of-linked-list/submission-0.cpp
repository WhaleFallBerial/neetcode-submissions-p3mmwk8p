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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> node;
        ListNode* curr=head;
        while(curr)
        {
            node.push_back(curr);
            curr=curr->next;
        }
        int remove_index=node.size()-n;
        if(remove_index==0)
        {
            return head->next;
        }
        node[remove_index-1]->next=node[remove_index]->next;
        return head;
    }
};
