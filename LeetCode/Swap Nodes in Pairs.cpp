// Question Link - https://leetcode.com/problems/swap-nodes-in-pairs/

// Solution Details - https://leetcode.com/submissions/detail/447737221/

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
    void swap(int *a, int *b){
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr)return NULL;
        ListNode *dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *p = new ListNode();
        ListNode *q = new ListNode();
        p = head;
        q = p -> next;
        int i=0;
        while(q != 0 ){
            if(i%2 == 0){
                swap(&(p -> val), &(q -> val));
            }
            i++;
            p = p -> next;
            q = q -> next;
        }
        return dummy -> next;
    }
};
