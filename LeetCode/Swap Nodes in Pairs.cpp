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

// ----------------------------------------------------------- APPROACH - 1 (By Swapping values of nodes) --------------------------------------------------------------
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

//------------------------------------------------------------ APPROACH - 2 (By Swapping the nodes itself) --------------------------------------------------------------

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *current = dummy;
        while(current -> next != NULL && current -> next -> next != NULL){
            ListNode *first_node = current -> next;
            ListNode *second_node = current -> next -> next;
            
            first_node -> next = second_node -> next;
            current -> next = second_node;
            second_node -> next = first_node;
            current = current -> next -> next;
            
        }
        return dummy -> next;
    }
};



