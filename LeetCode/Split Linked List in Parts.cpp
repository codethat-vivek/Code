// Question Link - https://leetcode.com/problems/split-linked-list-in-parts/

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
    int findLength(ListNode* head){
        int ans = 0;
        while(head){
            head = head -> next;
            ans ++;
        }
        return ans;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = findLength(head);
        int rem = len%k;
        int each = len/k;
        vector<ListNode*>ans;
        ListNode *q = head;
        // first rem boxes will contain each+1 items
        // then remaining boxes will contain each items
        
        for(int i=0; i<rem; i++){
            int t = each+1;
            ListNode *pre = head;
            while(t--){
                pre = head;
                head = head -> next;
            }
            pre -> next = NULL;
            ans.push_back(q);
            q = head;
        }
        for(int i=0; i<k-rem && head; i++){
            int t = each;
            ListNode *pre = head;
            while(t--){
                pre = head;
                head = head -> next;
            }
            pre -> next = NULL;
            ans.push_back(q);
            q = head;
        }
        while(ans.size() != k)
            ans.push_back(NULL);
        return ans;
    }
};
