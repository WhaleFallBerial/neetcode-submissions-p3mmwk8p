/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
    void dfs(Node*p, Node*q, unordered_set<Node*>& dp, unordered_set<Node*>& dq, Node* &res)
    {
        if (res) return;
        if (!p && !q) return;

        if (p) dp.insert(p);
        if (q) dq.insert(q);

        if(dp.find(q)!=dp.end())
        {
            res=q;
            return;
        }
            
        if(dq.find(p)!=dq.end())
        {
            res=p;
            return;
        }
            
        Node* np=p ? p->parent : nullptr;
        Node* nq=q ? q->parent : nullptr;
        dfs(np,nq,dp,dq,res);
        return;
    }
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*> dp, dq;
        Node* res=nullptr;
        dfs(p,q,dp, dq,res);
        return res;
    }


};