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
    string addstrings(const string& num1, const string& num2) {
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        string result;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';
            carry = sum / 10;
            result.push_back((sum % 10) + '0');
        }
        reverse(result.begin(), result.end());  // 因为是正序相加，最后反转
        return result;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string a1,a2;
        ListNode* c1=l1,*c2=l2;
        while(c1)
        {
            a1+=to_string(c1->val);
            c1=c1->next;
        }
        while(c2)
        {
            a2+=to_string(c2->val);
            c2=c2->next;
        }
        //long long i1=stol(a1);
        //long long i2=stol(a2);
        //long long nr=i1+i2;
        //string sr=to_string(nr);
        string sr=addstrings(a1,a2);
        int n=sr.size();
        ListNode* res=new ListNode(sr[0]-'0');
        ListNode *cur;
        cur=res;
        for(int i=1;i<n;i++)
        {
            cur->next=new ListNode(sr[i]-'0');
            cur=cur->next;
        }
        return res;
        
    }
};