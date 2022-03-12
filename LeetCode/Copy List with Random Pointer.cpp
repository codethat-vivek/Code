// Question Link - https://leetcode.com/problems/copy-list-with-random-pointer/

// Solution - 

class Solution {
public:
    Node* copyRandomList(Node* head) {
        /*
        Time - O(n)
        Space - O(n)
        */
        Node *temp = head;
        Node *ansHead = new Node(-1);
        Node *curr = ansHead;
        while(temp){
            curr -> next = new Node(temp -> val);
            temp = temp -> next;
            curr = curr -> next;
        }
        
        map<Node*, Node*>connector; 
        temp = head;
        curr = ansHead -> next;
        
        while(temp){
            connector[temp] = curr;
            temp = temp -> next;
            curr = curr -> next;
        }
        
        temp = head;
        curr = ansHead -> next;
        while(temp){
            curr -> random = connector[temp -> random];
            temp = temp -> next;
            curr = curr -> next;
        }
        
        return ansHead -> next;
        
    }
};

