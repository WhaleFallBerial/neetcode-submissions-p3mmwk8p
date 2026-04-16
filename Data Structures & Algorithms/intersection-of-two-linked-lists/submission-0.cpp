/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* cura=headA;
        ListNode* curb=headB;
        while(curb)
        {
            cura=headA;
            while(cura)
            {
                if(cura==curb)
                {
                    return curb;
                }
                cura=cura->next;
            }
            curb=curb->next;
        }
        return nullptr;
    }
};