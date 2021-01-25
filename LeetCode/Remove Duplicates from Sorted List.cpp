// Question Link - https://leetcode.com/problems/remove-duplicates-from-sorted-list/

// Solution Link - https://leetcode.com/submissions/detail/447748678/

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)return NULL;
        if (head -> next == NULL)return head;
        ListNode *dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *curr = head;
        ListNode *agla = head -> next;
        while(agla != 0){
            if(curr -> val == agla -> val){
                ListNode *del_node = agla;
                agla = agla -> next;
                curr -> next = agla;
                delete del_node;
            }
            else{
                curr = agla;
                agla = agla -> next;
            }
        }
        return dummy -> next;
    }
};
