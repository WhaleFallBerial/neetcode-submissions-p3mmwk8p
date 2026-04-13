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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head) return nullptr;

        ListNode *cur=head;
        while(cur->next)
        {
            int n1=cur->val;
            int n2=cur->next->val;
            int greatest_common_divisor=gcd(n1,n2);
            ListNode *gcd_node=new ListNode(greatest_common_divisor,cur->next);
            cur->next=gcd_node;
            cur=gcd_node->next;
        }

        return head;
    }

    int gcd(int a, int b)
    {
        
        while(b>0)
        {
            int tmp=b;
            b=a%b;
            a=tmp;
        }
        return a;
    }

};