// Question Link - https://leetcode.com/problems/linked-list-cycle/

// Solution - 

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *p=head, *q=head;
        if(head == NULL || head -> next == NULL)
            return false;
        do{
            p = p -> next;
            q = q -> next -> next;
            if(p == q)
                return true;
        }while(p && q && q -> next);
        return false;
    }
};
