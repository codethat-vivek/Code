// Question Link - https://leetcode.com/problems/merge-in-between-linked-lists/

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *tail = list2;
        while(tail -> next != NULL)
            tail = tail -> next;
        
        ListNode *ptr = list1, *qtr = list1, *temp = list1;
        b -= a;
        while(a){
            a--;
            ptr = temp;
            temp = temp -> next;
        }
        
        while(b){
            b--;
            temp = temp -> next;
        }
        qtr = temp;
        
        ptr -> next = list2;
        tail -> next = qtr -> next;
        
        
        return list1;
        
        
        
    }
};
