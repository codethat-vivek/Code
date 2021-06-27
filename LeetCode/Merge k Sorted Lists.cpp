// Question Link - https://leetcode.com/problems/merge-k-sorted-lists/

// Solution - 

class Solution {
public:
    ListNode* mergeTwo(ListNode *head, ListNode *head1){
        ListNode *dummy = new ListNode(100);
        ListNode *t = dummy;
        while(head != 0 && head1 != 0){
            if(head -> val <= head1 -> val){
                t -> next = head;
                t = t -> next;
                head = head -> next;
            }
            else{
                t -> next = head1;
                t = t -> next;
                head1 = head1 -> next;
            }
        }
        if(head){
            t -> next = head;
            t = t ->  next;
        }
        if(head1){
            t -> next = head1;
            t = t-> next;
        }
        return dummy -> next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0)
            return NULL;
        if(n == 1)
            return lists[0];
        
        ListNode *dummy = mergeTwo(lists[0], lists[1]);
        
        for(int i=2; i<n; i++){
            dummy = mergeTwo(dummy, lists[i]);
        }
        return dummy;
    }
};
