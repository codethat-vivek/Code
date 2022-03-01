// Question Link - https://leetcode.com/problems/sum-of-two-integers/

// Solution - 

class Solution {
public:
    string reverse(string s){
        string rev = "";
        for(char c : s)
            rev = c + rev;
        return rev;
    }
    
    int binaryToDecimal(string n){
        string num = n;
        long long int dec_value = 0;
        long long int base = 1;
        int len = num.length();
        for (int i = len - 1; i >= 0; i--) {
            if (num[i] == '1')
                dec_value += base;
            base = base * 2;
        }

        return dec_value;
    }

    int getSum(int a, int b) {
        /*
            110
            101
           -----
           1011
           -----
        #Both bits are same then output for that corresponding should be 0 + prevCarry
        #If bits are different then output for that corresponding should be 1 + prevCarry
        */
        
        string ans = "";
        long long int x=1, y=1, first, second;
        int carry = 0;
        for(int i=0; i<32; i++){
            first = x & a;
            second = y & b;

            if(first == 0 && second == 0 && carry == 0)
                ans += '0';

            else if(first == 0 && second == 0 && carry == 1){
                ans += '1';
                carry = 0;
            }
            else if(first == 0 && second != 0 && carry == 0)
                ans += '1';

            else if(first == 0 && second != 0 && carry == 1)
                ans += '0';

            else if(first != 0 && second == 0 && carry == 0)
                ans += '1';

            else if(first != 0 && second == 0 && carry == 1)
                ans += '0';
                
            else if(first != 0 && second != 0 && carry == 0){
                ans += '0';
                carry = 1;
            }
            else if(first != 0 && second != 0 && carry == 1)
                ans += '1';
            
            x = x << 1;
            y = y << 1;
        }
        ans = reverse(ans);
        return binaryToDecimal(ans);
        
    }
};
