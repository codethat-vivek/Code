// Question Link - https://leetcode.com/problems/remove-linked-list-elements/

// Solution - 

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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)return head;
        if(!head -> next){
            if(head -> val == val)
                return NULL;
            return head;
        }
        ListNode *temp = new ListNode(-1);
        temp -> next = head;
        ListNode *p, *q, *r, *dummy;
        dummy = temp;
        p = temp;
        q = head;
        r = head -> next;
        //cout << p -> val << " " << q -> val << " " << r -> val << endl;
        while(q){
            if(q -> val == val){
                q -> next = NULL;
                p -> next = r;
                q = r;
            }
            else{
                p = p -> next;
                q = q -> next;
            }
            if(r)
                r = r -> next; 
        }
        return dummy -> next;
    }
};
