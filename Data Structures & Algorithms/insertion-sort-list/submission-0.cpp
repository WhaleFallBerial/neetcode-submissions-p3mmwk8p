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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* cur=head;
        vector<int> arr;
        while(cur)
        {
            arr.push_back(cur->val);
            cur=cur->next;
        }
        int n=arr.size();
        int index=0;
        while(index<n)
        {
            int tmp=min_element(arr.begin()+index, arr.end())-arr.begin();
            int desk=arr[index];
            arr[index]=arr[tmp];
            arr[tmp]=desk;
            index++;
        }
        ListNode* res=new ListNode(arr[0]);
        cur=res;
        for(int i=1;i<n;i++)
        {
            cur->next=new ListNode(arr[i]);
            cur=cur->next;
        }
        return res;
    }
};