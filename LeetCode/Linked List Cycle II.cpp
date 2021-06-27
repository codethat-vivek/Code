// Question Link - https://leetcode.com/problems/linked-list-cycle-ii/

// Solution - 

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL)
            return NULL;
        ListNode *o = head;
        ListNode *t = head;

        while(o != NULL && t != NULL && t-> next != NULL){
            o = o -> next;
            t = t -> next -> next;
            if(o == t){
                // it means we have a loop
                o = head;
                while(o != t){
                    o = o->next;
                    t = t->next;
                }
                return o;
            }
        }
        return NULL;
    }
};
