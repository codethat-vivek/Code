// Question Link - https://leetcode.com/problems/middle-of-the-linked-list/

// Solution - 

class Solution {
public:
    int findLength(ListNode* head){
        int len = 0;
        while(head){
            head = head -> next;
            len++;
        }
        return len;
    }
    ListNode* middleNode(ListNode* head) {
        int jumps = findLength(head)/2;
        while(jumps--)
            head = head -> next;
        return head;
    }
};
