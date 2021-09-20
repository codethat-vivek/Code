// Question Link - https://leetcode.com/problems/odd-even-linked-list/

// Solution - 

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
            return NULL;
        if(head -> next == NULL || head -> next -> next == NULL)
            return head;
        ListNode* odd = new ListNode(0);
        ListNode* even = new ListNode(0);
        ListNode *e = even, *o = odd;
        int i = 1;
        ListNode *p = head, *q = head -> next;
        // Always segreate the nodes and then add nodes to odd or even pointer
        while(p){
            p -> next = NULL;
            if(i % 2 != 0){
                o -> next = p;
                o = o -> next;
            }
            else{
                e -> next = p;
                e = e -> next;
            }
            p = q;
            if(q != NULL)
                q = q -> next;
            
            i += 1;
        }
        o -> next = even -> next;
        return odd -> next;
    }
};
