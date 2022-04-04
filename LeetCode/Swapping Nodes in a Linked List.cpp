// Question Link - https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int>nodes;
        ListNode *temp = head;
        while(temp){
            nodes.push_back(temp -> val);
            temp = temp -> next;
        }
        int j=nodes.size()-k;
        int t = nodes[j];
        nodes[j] = nodes[k-1];
        nodes[k-1] = t;
        
        
        ListNode *ans = new ListNode(-1);
        ListNode *curr = ans;
        for(int i : nodes){
            ListNode *node = new ListNode(i);
            curr -> next = node;
            curr = curr -> next;
        }
        return ans -> next;
        
    }
};
