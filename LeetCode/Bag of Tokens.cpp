// Question Link - https://leetcode.com/problems/bag-of-tokens/

// Solution - 

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        // if we have power >= tokens[i], then greedily I should take tokens[i] so as to increase the score
        // if we don't have enough power and score = 0 then we return
        // if we don't have enough power and score > 0 then we need to play this token face down
        
        int p=power, score=0;
        int s=0;
        int n=tokens.size();
        int i=0, j=n-1;
        
        while(i <= j){
            if(p >= tokens[i]){
                p -= tokens[i++];
                s += 1;
                score = max(score, s);
            }
            else{
                if(s == 0){
                    i ++;
                    continue;
                }
                else{
                    p += tokens[j--];
                    s -= 1;
                    score = max(score, s);
                }
            }
        }
        score = max(score, s);
        
        return score;
        
    }
};
