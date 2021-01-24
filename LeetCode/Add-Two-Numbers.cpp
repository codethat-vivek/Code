// Question Link - https://leetcode.com/problems/add-two-numbers/

// Solution Link - https://leetcode.com/submissions/detail/446883872/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode();
        ListNode *temp = head;
        int carry = 0;
        while(l1 != 0 || l2 != 0 || carry){
            int sum = 0;
            if(l1 != NULL){
                sum += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2 != NULL){
                sum += l2 -> val;
                l2 = l2 -> next;
            }
            sum += carry;
            carry = sum/10;
            ListNode *lastDigit = new ListNode(sum%10);
            temp -> next = lastDigit;
            temp = temp -> next;
        }
        return head -> next;
    }
};
