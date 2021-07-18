// Question Link - https://leetcode.com/problems/reverse-nodes-in-k-group/

// Solution - 

class Solution {
public:
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(105);
        dummy -> next = head;
        ListNode *temp = head, *prev = dummy;
        int i=1;
        while (temp != 0){
            if(i == left){
                ListNode* tt = temp;
                ListNode *p = temp;
                ListNode *q = NULL;
                while(i != right+1){
                    temp = temp -> next;
                    p -> next = q;
                    q = p;
                    p = temp;
                    i++;
                }
                // 4 -> q; 5 -> temp, p;
                prev -> next = q;
                tt -> next = temp;
                return dummy -> next;
            }
            prev = temp;
            temp = temp -> next;
            i++;
        }
        return dummy -> next;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * temp = head;
        int h = 0;
        while(temp != 0){
            temp = temp -> next;
            h += 1;
        }
        int left = 1;
        //cout << h << endl;
        while(left < h){
            if(left + k - 1 > h)
                break;
            head = reverseBetween(head, left, left+k-1);
            left = left+k;
        }
        return head;
    }
};
