// Question Link - https://leetcode.com/problems/reverse-linked-list/

// Solution Details - https://leetcode.com/submissions/detail/447761089/

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
    ListNode* reverseList(ListNode* head) {
        // By Iterative Method using three pointers 
        ListNode *p = NULL;
        ListNode *q = NULL;
        ListNode *r = head;
        while(r != NULL){
            q = r -> next;
            r -> next = p;
            p = r;
            r = q;
        }
        return p;
    }
};
