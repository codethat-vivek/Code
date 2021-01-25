// Question Link - https://leetcode.com/problems/merge-two-sorted-lists/

// Solution Link - https://leetcode.com/submissions/detail/446893349/

// SOLUTION - 

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *temp = head;
        while(l1 != 0 && l2 != 0){
            if(l1 -> val < l2 -> val){
                temp -> next = l1; 
                l1 = l1 -> next;
            }
            else{
                temp -> next = l2;
                l2 = l2 -> next;
            }
            temp = temp -> next;
        }
        while(l1 != 0){
            temp -> next = l1;
            temp = temp -> next;
            l1 = l1 -> next;
        }
        while(l2 != 0){
            temp -> next = l2;
            temp = temp -> next;
            l2 = l2 -> next;
        }
        return head -> next;
    }
};
