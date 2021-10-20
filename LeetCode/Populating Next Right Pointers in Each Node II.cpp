// Question Link - 

// Solution - 

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return NULL;
        queue<Node*>q;
        vector<Node*>t;
        q.push(root);
        while(!q.empty()){
            int len = (int)q.size();
            t.clear();
            while(len--){
                Node* temp = q.front();
                t.push_back(temp);
                q.pop();
                if(temp -> left)q.push(temp -> left);
                if(temp -> right)q.push(temp -> right);
            }
            for(int i=0; i<t.size()-1; i++)
                t[i] -> next = t[i+1];
            //t[t.size()-1] -> next = NULL;
        }
        return root;
    }
};
