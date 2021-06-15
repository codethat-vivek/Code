// Question Link - https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
    ListNode* answerFunction(ListNode *head){
        ListNode *p = head -> next -> next;
        ListNode *q = head -> next;
        ListNode *r = head;
        while(p != 0){
            if(p -> val == q -> val){
                while(p != 0 && p -> val == q -> val)
                    p = p -> next;
                if(p == NULL){
                    r -> next = NULL;
                    return head;
                }
                if(p != NULL){
                    r -> next = p;
                    q = p;
                    p = p -> next;
                }
            }
            else{
                p = p -> next;
                q = q -> next;
                r = r -> next;
            }
        }
        return head;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return NULL;
        
        if(head -> next == NULL)
            return head;
      
        // creating a new dummy node
        ListNode *d1 = new ListNode(-101);
        d1 -> next = head;          
        
        ListNode * dummy = answerFunction(d1);
        return dummy -> next;
        
    }
};
