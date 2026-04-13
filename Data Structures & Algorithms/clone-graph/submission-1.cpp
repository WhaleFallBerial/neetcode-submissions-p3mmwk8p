/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*,Node*> otn;
        return dfs(node,otn);
    }

    Node* dfs(Node* node,map<Node*,Node*>& otn)
    {
        if(!node) return nullptr;
        if(otn.count(node)) return otn[node];

        Node* copy=new Node(node->val);
        otn[node]=copy;
        for(Node* n:node->neighbors)
        {
            copy->neighbors.push_back(dfs(n,otn));
        }
        return copy;
    }
};
