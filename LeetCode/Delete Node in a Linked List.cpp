// Question Link - https://leetcode.com/problems/delete-node-in-a-linked-list/

// Solution Details - https://leetcode.com/submissions/detail/447771994/

// SOLUTION - 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // Tricky Question
        ListNode *prev = node;
        while(node -> next != 0){
            ListNode *temp = node -> next;
            node -> val = temp -> val;
            prev = node;
            node = node -> next;
        }
        prev -> next = NULL;
        delete node;
        
    }
};
