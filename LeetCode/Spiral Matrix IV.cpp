// Question Link - https://leetcode.com/problems/spiral-matrix-iv/

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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int i=0, j=0;
        bool left=false, right=true, top=false, down=false;
        while(head){
            ans[i][j] = head -> val;
            head = head -> next;
            if(right){
                j += 1;
                if(j == n || ans[i][j] != -1){
                    j -= 1;
                    i += 1;
                    down = true;
                    right = false;
                }
            }
            else if(down){
                i += 1;
                if(i == m || ans[i][j] != -1){
                    i -= 1;
                    j -= 1;
                    down = false;
                    left = true;
                }
            }
            else if(left){
                j -= 1;
                if(j == -1 || ans[i][j] != -1){
                    j += 1;
                    i -= 1;
                    left = false;
                    top = true;
                }
            }
            else if(top){
                i -= 1;
                if(i == -1 || ans[i][j] != -1){
                    i += 1;
                    j += 1;
                    top = false;
                    right = true;
                }
            }
        }
        return ans;
    }
};
