// Question Link - https://leetcode.com/problems/rotate-list/

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
    int findLength(ListNode *head){
        int len = 0;
        while(head){
            len ++;
            head = head -> next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)return 0;
        int n = findLength(head);
        k = k % n;
        if(head -> next == NULL || k == 0)return head;
        
        int jumps = n-k-1;
        ListNode *temp = head;
        while(jumps--)
            temp = temp -> next;
        ListNode *newStart = temp -> next;
        temp -> next = NULL;
        ListNode *end = newStart;
        while(end -> next)
            end = end -> next;
        end -> next = head;
        return newStart;
    }
};
