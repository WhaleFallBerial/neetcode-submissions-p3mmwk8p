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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr) return nullptr;
        ListNode* cur=head;
        vector<int> arr;
        while(cur)
        {
            arr.push_back(cur->val);
            cur=cur->next;
        }
        int n=arr.size();
        vector<int> adp(n);
        for(int i=0;i<n;i++)
        {
            int tmp=(i+k)%n;
            adp[tmp]=arr[i];
        }
        ListNode* res=new ListNode(adp[0]);
        cur=res;
        for(int i=1;i<n;i++)
        {
            cur->next=new ListNode(adp[i]);
            cur=cur->next;
        }
        return res;
    }
};