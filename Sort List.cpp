// Question Link - https://leetcode.com/problems/sort-list/

// Solution - 

class Solution {
public:
    
    ListNode *merge(ListNode *head1, ListNode *head2){
        ListNode *ans = new ListNode(-1);
        ListNode *temp = ans;
        while(head1 && head2){
            if(head1 -> val < head2 -> val){
                temp -> next = head1;
                head1 = head1 -> next;
            }
            else{
                temp -> next = head2;
                head2 = head2 -> next;
            }
            temp = temp -> next;
        }
        if(head1)
            temp -> next = head1;
        if(head2)
            temp -> next = head2;
        return ans -> next;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL)
            return head;
        
        ListNode *fast = head, *slow = head, *temp = head;
        while(fast && fast -> next){
            temp = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        temp -> next = NULL;
        ListNode *head1 = sortList(head);
        ListNode *head2 = sortList(slow);
        
        return merge(head1, head2);
        
    }
};
