// Question Link - https://leetcode.com/problems/remove-nth-node-from-end-of-list/

// Solution Link - https://leetcode.com/submissions/detail/447146091/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *another = new ListNode(-1);
        another -> next = head;
        ListNode *p = new ListNode();
        ListNode *q = new ListNode();
        p = another;
        q = another;
        
        int i=0;
        while(i<=n){
            q = q -> next;
            i++;
        }
        while(q != 0){
            q = q -> next;
            p = p -> next;
        }
        p -> next = p -> next -> next;
        
        return another -> next;
        
    }
};
