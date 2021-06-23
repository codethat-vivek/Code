// Question Link - https://leetcode.com/problems/reverse-linked-list-ii/

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(105);
        dummy -> next = head;
        ListNode *temp = head, *prev = dummy;
        int i=1;
        while (temp != 0){
            if(i == left){
                ListNode* tt = temp;
                ListNode *p = temp;
                ListNode *q = NULL;
                while(i != right+1){
                    temp = temp -> next;
                    p -> next = q;
                    q = p;
                    p = temp;
                    i++;
                }
                // 4 -> q; 5 -> temp, p;
                prev -> next = q;
                tt -> next = temp;
                return dummy -> next;
            }
            prev = temp;
            temp = temp -> next;
            i++;
        }
        return dummy -> next;
    }
};
